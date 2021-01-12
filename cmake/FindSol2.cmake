find_path(Sol2_INCLUDE_DIR NAMES sol/sol.hpp)

if(Sol2_INCLUDE_DIR AND EXISTS "${Sol2_INCLUDE_DIR}/sol/version.hpp")
	file(STRINGS "${Sol2_INCLUDE_DIR}/sol/version.hpp" sol2_version_str REGEX "^#define[ \t]+SOL_VERSION_STRING[ \t]+\".+\"")
	string(REGEX REPLACE "^#define[ \t]+SOL_VERSION_STRING[ \t]+\"([^\"]+)\".*" "\\1" Sol2_VERSION_STRING "${sol2_version_str}")
	unset(sol2_version_str)
endif()


include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Sol2 REQUIRED_VARS Sol2_INCLUDE_DIR VERSION_VAR Sol2_VERSION_STRING)

mark_as_advanced(Sol2_INCLUDE_DIR)

