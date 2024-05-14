#include "../otpch.h"

#include "login.h"

#include "../database.h"
#include "../tools.h"
#include "error.h"

#include <fmt/format.h>

std::pair<boost::beast::http::status, boost::json::value> tfs::http::handle_login(const boost::json::object& body)
{
	assert(body.at("type").as_string() == "login");

	auto emailField = body.if_contains("email");
	if (!emailField || !emailField->is_string()) {
		return make_error_response(
		    {.code = 3, .message = "Tibia account email address or Tibia password is not correct."});
	}

	auto& db = Database::getInstance();
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

		uint32_t ticks = now.count() / AUTHENTICATOR_PERIOD;
		if (token->get_string() != generateToken(secret, ticks) &&
		    token->get_string() != generateToken(secret, ticks - 1) &&
		    token->get_string() != generateToken(secret, ticks + 1)) {
			return make_error_response({.code = 6, .message = "Two-factor token required for authentication."});
		}
	}

	return {boost::beast::http::status::ok, {}};
}
