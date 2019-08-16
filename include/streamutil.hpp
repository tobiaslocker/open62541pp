#include <iostream>
#include <algorithm>

namespace streamutil {

template <typename T>
inline void print_container(std::ostream &out, const T &op) {
  if (!op.empty()) {
    std::for_each(op.begin(),
                  op.end() - 1,
                  [&](auto const &u) { out << u << ", "; });
    out << op.back();
  }
}

template <typename T>
inline void print_container_quoted(std::ostream &out, const T &op) {
  if (!op.empty()) {
    std::for_each(op.begin(),
                  op.end() - 1,
                  [&](auto const &u) { out << u << ", "; });
    out << op.back();
  }
}

}
