#include <libcpplog/utils/tree/Node.hpp>

#include <span>
#include <utility>

namespace cpplog::utils::tree {

	template <typename TIdentifier>
	Node<TIdentifier>::Node(const TIdentifier& id) noexcept
		: id{ id } {
	
	}

	template <typename TIdentifier>
	template <typename NodeLike>
		requires std::same_as<std::remove_cvref_t<NodeLike>, Node<TIdentifier>>
	void Node<TIdentifier>::add(NodeLike&& node) {
		childNodes.push_back(std::forward<NodeLike>(node));
	}

	template <typename TIdentifier>
	const TIdentifier& Node<TIdentifier>::getId() const noexcept {
		return id;
	}

	template <typename TIdentifier>
	Node<TIdentifier>::iterator Node<TIdentifier>::begin() {
		return childNodes.begin();
	}

	template <typename TIdentifier>
	Node<TIdentifier>::iterator	Node<TIdentifier>::end() {
		return childNodes.end();
	}

	template <typename TIdentifier>
	Node<TIdentifier>::const_iterator Node<TIdentifier>::cbegin() const {
		return childNodes.cbegin();
	}

	template <typename TIdentifier>
	Node<TIdentifier>::const_iterator Node<TIdentifier>::cend() const {
		return childNodes.cend();
	}

	template <typename TIdentifier>
	std::span<Node<TIdentifier>> Node<TIdentifier>::getChildNodes() {
		return std::span(begin(), end());
	}

	template <typename TIdentifier>
	std::span<const Node<TIdentifier>> Node<TIdentifier>::getChildNodes() const {
		return std::span(cbegin(), cend());
	}

}