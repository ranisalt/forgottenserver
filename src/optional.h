#ifndef TFS_OPTIONAL_H
#define TFS_OPTIONAL_H

#if __cplusplus >= 201703L
#include <optional>
namespace tfs {
using std::make_optional;
using std::optional;
}
#else
#include <boost/optional.hpp>
namespace tfs {
using boost::make_optional;
using boost::optional;
}
#endif

#endif //TFS_OPTIONAL_H
