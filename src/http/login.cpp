#include "../otpch.h"

#include "login.h"

#include "../configmanager.h"
#include "../database.h"
#include "../tools.h"
#include "../vocation.h"
#include "error.h"

#include <fmt/format.h>

extern Vocations g_vocations;

namespace {

auto& db = Database::getInstance();

int getPvpType()
{
	auto worldType = boost::algorithm::to_lower_copy(getString(ConfigManager::WORLD_TYPE));

	if (worldType == "pvp") {
		return 0;
	} else if (worldType == "no-pvp") {
		return 1;
	} else if (worldType == "pvp-enforced") {
		return 2;
	}

	tfs::unreachable();
}

} // namespace

std::pair<boost::beast::http::status, boost::json::value> tfs::http::handle_login(const boost::json::object& body)
{
	assert(body.at("type").as_string() == "login");

	auto emailField = body.if_contains("email");
	if (!emailField || !emailField->is_string()) {
		return make_error_response(
		    {.code = 3, .message = "Tibia account email address or Tibia password is not correct."});
	}

	auto result = db.storeQuery(fmt::format(
	    "SELECT `id`, UNHEX(`password`) AS `password`, `secret`, `premium_ends_at` FROM `accounts` WHERE `email` = {:s}",
	    db.escapeString(emailField->get_string())));
	if (!result) {
		return make_error_response(
		    {.code = 3, .message = "Tibia account email address or Tibia password is not correct."});
	}

	auto passwordField = body.if_contains("password");
	if (!passwordField || !passwordField->is_string()) {
		return make_error_response(
		    {.code = 3, .message = "Tibia account email address or Tibia password is not correct."});
	}

	auto password = result->getString("password");
	if (password != transformToSHA1(passwordField->get_string())) {
		return make_error_response(
		    {.code = 3, .message = "Tibia account email address or Tibia password is not correct."});
	}

	using namespace std::chrono;
	auto now = duration_cast<seconds>(system_clock::now().time_since_epoch());

	auto secret = result->getString("secret");
	if (!secret.empty()) {
		auto token = body.if_contains("token");
		if (!token || !token->is_string()) {
			return make_error_response({.code = 6, .message = "Two-factor token required for authentication."});
		}

		uint64_t ticks = now.count() / AUTHENTICATOR_PERIOD;
		if (token->get_string() != generateToken(secret, ticks) &&
		    token->get_string() != generateToken(secret, ticks - 1) &&
		    token->get_string() != generateToken(secret, ticks + 1)) {
			return make_error_response({.code = 6, .message = "Two-factor token required for authentication."});
		}
	}

	auto accountId = result->getNumber<uint64_t>("id");
	auto premiumEndsAt = result->getNumber<int64_t>("premium_ends_at");

	result = db.storeQuery(fmt::format(
	    "SELECT `id`, `name`, `level`, `vocation`, `lastlogin`, `sex`, `looktype`, `lookhead`, `lookbody`, `looklegs`, `lookfeet`, `lookaddons` FROM `players` WHERE `account_id` = {:d}",
	    accountId));

	boost::json::array characters;
	uint32_t lastLogin = 0;
	if (result) {
		do {
			auto vocation = g_vocations.getVocation(result->getNumber<uint32_t>("vocation"));

			characters.push_back({
			    {"worldid", 0},
			    {"name", result->getString("name")},
			    {"level", result->getNumber<uint32_t>("level")},
			    {"vocation", vocation->getVocName()},
			    {"lastlogin", result->getNumber<uint64_t>("lastlogin")},
			    {"ismale", true},
			    {"ishidden", false},
			    {"ismaincharacter", false},
			    {"tutorial", false},
			    {"outfitid", result->getNumber<uint32_t>("looktype")},
			    {"headcolor", result->getNumber<uint32_t>("lookhead")},
			    {"torsocolor", result->getNumber<uint32_t>("lookbody")},
			    {"legscolor", result->getNumber<uint32_t>("looklegs")},
			    {"detailcolor", result->getNumber<uint32_t>("lookfeet")},
			    {"addonsflags", result->getNumber<uint32_t>("lookaddons")},
			    {"dailyrewardstate", 0},
			});

			lastLogin = std::max(lastLogin, result->getNumber<uint32_t>("lastlogin"));
		} while (result->next());
	}

	boost::json::array worlds{
	    {
	        {"id", 0},
	        {"name", getString(ConfigManager::SERVER_NAME)},
	        {"externaladdressprotected", getString(ConfigManager::IP)},
	        {"externalportprotected", getNumber(ConfigManager::GAME_PORT)},
	        {"externaladdressunprotected", getString(ConfigManager::IP)},
	        {"externalportunprotected", getNumber(ConfigManager::GAME_PORT)},
	        {"previewstate", 0},
	        {"location", getString(ConfigManager::LOCATION)},
	        {"anticheatprotection", true},
	        {"pvptype", getPvpType()},
	    },
	};

	return {
	    boost::beast::http::status::ok,
	    {
	        {"session",
	         {
	             {"sessionkey", "TODO"},
	             {"lastlogintime", lastLogin},
	             {"ispremium", premiumEndsAt >= now.count()},
	             {"premiumuntil", premiumEndsAt},
	             {"status", "active"},
	             {"returnernotification", true},
	             {"showrewardnews", true},
	             {"isreturner", false},
	             {"recoverysetupcomplete", true},
	             {"fpstracking", false},
	             {"optiontracking", false},
	         }},
	        {"playdata",
	         {
	             {"worlds", worlds},
	             {"characters", characters},
	         }},
	    },
	};
}
