set(http_SRC
	${CMAKE_CURRENT_LIST_DIR}/fail.cpp
	${CMAKE_CURRENT_LIST_DIR}/http.cpp
	${CMAKE_CURRENT_LIST_DIR}/json.cpp
	${CMAKE_CURRENT_LIST_DIR}/listener.cpp
	${CMAKE_CURRENT_LIST_DIR}/lua.cpp
	${CMAKE_CURRENT_LIST_DIR}/session.cpp
	)

set(http_HDR
	${CMAKE_CURRENT_LIST_DIR}/fail.h
	${CMAKE_CURRENT_LIST_DIR}/http.h
	${CMAKE_CURRENT_LIST_DIR}/json.h
	${CMAKE_CURRENT_LIST_DIR}/listener.h
	${CMAKE_CURRENT_LIST_DIR}/lua.h
	${CMAKE_CURRENT_LIST_DIR}/session.h
	)

add_library(http OBJECT ${http_SRC})
target_link_libraries(http PRIVATE Boost::json ${LUA_LIBRARIES})
