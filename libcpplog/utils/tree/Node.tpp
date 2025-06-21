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
		return Node<TIdentifier>::iterator(childNodes.begin());
	}

	template <typename TIdentifier>
	Node<TIdentifier>::iterator	Node<TIdentifier>::end() {
		return Node<TIdentifier>::iterator(childNodes.end());
	}

	template <typename TIdentifier>
	Node<TIdentifier>::const_iterator Node<TIdentifier>::cbegin() const {
		return Node<TIdentifier>::iterator(childNodes.cbegin());
	}

	template <typename TIdentifier>
	Node<TIdentifier>::const_iterator Node<TIdentifier>::cend() const {
		return Node<TIdentifier>::iterator(childNodes.end());
	}

	template <typename TIdentifier>
	std::span<Node<TIdentifier>> Node<TIdentifier>::getChildNodes() {
		return std::span(begin(), end());
	}

	/**
	 * @brief Get the child nodes
	 *
	 * @return A span over the child nodes
	 * 
	 * @details
	 * The iterator type only affects how the span is constructed and not how it
	 * behaves after construction. Mutabiliy of the span is determined by the
	 * span's template parameter (here `const` is used).
	 */
	template <typename TIdentifier>
	std::span<const Node<TIdentifier>> Node<TIdentifier>::getChildNodes() const {
		return std::span(begin(), end());
	}

}