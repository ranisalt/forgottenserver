#pragma once

#ifdef USE_FOLLY

#include <folly/FBVector.h>

namespace tfs {

template<class T>
using vector = folly::fbvector<T>;

}

#else

#include <vector>

namespace tfs {

template<class T>
using vector = std::vector<T>;

}

#endif
