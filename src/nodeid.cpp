#include <iomanip>

#include "nodeid.hpp"
#include "parser.hpp"

namespace open62541 {

class NodeId::impl {
  uint16_t m_namespace_index = 0;
  Identifier m_identifier;
  IdentifierType m_identifier_type;
  bool m_empty = false;

 public:
  impl() : m_empty{true} {}

  impl(uint16_t namespace_index,
       Identifier const &identifier,
       IdentifierType type)
      : m_namespace_index{namespace_index},
        m_identifier{identifier},
        m_identifier_type{type} {}

  Identifier identifier() const { return m_identifier; }

  IdentifierType identifier_type() const { return m_identifier_type; }

  uint16_t namespace_index() const { return m_namespace_index; }

  bool empty() const { return m_empty; }

  bool operator==(impl const &rhs) const {
    return identifier() == rhs.identifier() &&
           namespace_index() == rhs.namespace_index();
  }

  bool operator!=(impl const &rhs) const {
    return identifier() != rhs.identifier() ||
           namespace_index() != rhs.namespace_index();
  }
};

NodeId::NodeId() : d_ptr{std::make_unique<impl>()} {}

NodeId::NodeId(NodeId &&) noexcept = default;

NodeId &NodeId::operator=(NodeId &&) noexcept = default;

NodeId::~NodeId() = default;

NodeId::NodeId(NodeId const &op) : d_ptr(new impl(*op.d_ptr)) {}

NodeId &NodeId::operator=(NodeId const &op) {
  if (this != &op) {
    d_ptr.reset(new impl(*op.d_ptr));
  }
  return *this;
}

NodeId::NodeId(uint16_t namespace_index,
               Identifier const &identifier,
               IdentifierType type)
    : d_ptr{std::make_unique<impl>(namespace_index, identifier, type)} {}

Identifier NodeId::identifier() const { return d_ptr->identifier(); }

IdentifierType NodeId::identifier_type() const {
  return d_ptr->identifier_type();
}

uint16_t NodeId::namespace_index() const { return d_ptr->namespace_index(); }

bool NodeId::empty() const { return d_ptr->empty(); }

bool NodeId::operator==(NodeId const &rhs) const {
  return *d_ptr == *rhs.d_ptr;
}

bool NodeId::operator!=(NodeId const &rhs) const {
  return *d_ptr != *rhs.d_ptr;
}

std::ostream &operator<<(std::ostream &out, const NodeId &op) {
  std::string id;
  if (op.identifier_type() == IdentifierType::String ||
      op.identifier_type() == IdentifierType::ByteString) {
    out << "{" << op.namespace_index() << ", "
        << std::quoted(op.identifier().string()) << ", " << op.identifier_type()
        << "}";
  } else if (op.identifier_type() == IdentifierType::Numeric) {
    out << "{" << op.namespace_index() << ", " << op.identifier().numeric()
        << ", " << op.identifier_type() << "}";
  } else if (op.identifier_type() == IdentifierType::Guid) {
    out << "{" << op.namespace_index() << ", " << op.identifier().guid() << ", "
        << op.identifier_type() << "}";
  }
  return out;
}

}  // namespace open62541
