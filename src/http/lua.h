#pragma once

#include "session.h"

#include <boost/beast/http/message_generator.hpp>
#include <memory>

struct lua_State;

namespace tfs::http {

boost::beast::http::message_generator handle_request(Request&& req);

} // namespace tfs::http
