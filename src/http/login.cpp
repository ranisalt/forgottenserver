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
	    "SELECT `id`, UNHEX(`password`) AS `password`, `secret`, `type`, `premium_ends_at` FROM `accounts` WHERE `email` = {:s}",
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

	// auto token = body.if_contains("token");

	return {boost::beast::http::status::ok, {}};
}
