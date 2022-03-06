#pragma once

#ifdef TSL_ROBIN_MAP

#include <tsl/robin_map.h>
#include <tsl/robin_set.h>

namespace tfs {

template<typename Key, typename Value>
using unordered_map = tsl::robin_map<Key, Value>;

template<typename Value>
using unordered_set = tsl::robin_set<Value>;

}

#else

#include <unordered_map>
#include <unordered_set>

namespace tfs {

template<typename Key, typename Value>
using unordered_map = std::unordered_map<Key, Value>;

template<typename Value>
using unordered_set = std::unordered_set<Value>;

}

#endif
