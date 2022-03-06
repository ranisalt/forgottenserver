# Locate tsl::robin_map library
# This module defines
#   TslRobinMap_FOUND
#   TslRobinMap_INCLUDE_DIR

find_path(TslRobinMap_INCLUDE_DIR NAMES tsl/robin_map.h)

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(TslRobinMap DEFAULT_MSG TslRobinMap_INCLUDE_DIR)

mark_as_advanced(TslRobinMap_INCLUDE_DIR)
