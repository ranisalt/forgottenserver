set(luaengine_SRC
	${CMAKE_CURRENT_LIST_DIR}/luascript.cpp
	${CMAKE_CURRENT_LIST_DIR}/luautils.cpp
	)

add_library(luaengine OBJECT ${luaengine_SRC})

