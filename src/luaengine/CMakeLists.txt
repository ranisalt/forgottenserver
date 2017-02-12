set(luaengine_SRC
	${CMAKE_CURRENT_LIST_DIR}/functions.cpp
	${CMAKE_CURRENT_LIST_DIR}/luascript.cpp
	)

add_library(luaengine ${luaengine_SRC})

include_directories(${LUA_INCLUDE_DIR})
target_link_libraries(luaengine ${LUA_LIBRARIES})
