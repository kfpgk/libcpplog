#pragma once

#include <concepts>
#include <span>
#include <vector>

namespace cpplog::utils::tree {

	/**
	 * @brief Node class for a tree structure
	 * 
	 * @details
	 * Patterns:
	 *  - Tree
	 */
	template <typename TIdentifier>
	class Node {

	public:
		/**
		 * @brief Type alias for the child container
		 */
		using ChildContainer = std::vector<Node<TIdentifier>>;

		/**
		 * @brief Type alias for the iterator for this class
		 * 
		 * @details
		 * lower case `iterator` is used to comply with the `std` iterator naming
		 */
		using iterator = typename ChildContainer::iterator;

		/**
		 * @brief Type alias for the iterator for this class
		 *
		 * @details
		 * lower case `const_iterator` is used to comply with the `std` iterator naming
		 */
		using const_iterator = typename ChildContainer::const_iterator;

		/**
		 * @brief Constructor
		 * 
		 * @param[in] id The identifier of the node
		 */
		Node(const TIdentifier& id) noexcept;

		/**
		 * @brief Add a node as a child node by perferct forwarding
		 * 
		 * This copies or moves the \p node object depending on
		 * value category.
		 * 
		 * @param[in] node The node to be added as a child node
		 */
		template <typename NodeLike>
			requires std::same_as<std::remove_cvref_t<NodeLike>, Node<TIdentifier>>
		void add(NodeLike&& node);

		/**
		 * @brief Get the identifier of the node
		 *
		 * @return The identifier of the node
		 */
		const TIdentifier& getId() const noexcept;

		/**
		 * @brief Get the beginning of the child nodes container
		 * 
		 * @return An iterator to the first element of the child nodes
		 */
		iterator begin();

		/**
		 * @brief Get the end of the child nodes container
		 * 
		 * @return An iterator to the (invalid) element past the last element of the child nodes
		 */
		iterator end();

		/**
		 * @brief Get the beginning of the child nodes container
		 *
		 * @return A const iterator to the first element of the child nodes
		 */
		const_iterator cbegin() const;

		/**
		 * @brief Get the end of the child nodes container
		 *
		 * @return A const iterator to the (invalid) element past the last element of the child 
		 * nodes
		 */
		const_iterator cend() const;

		/**
		 * @brief Get the child nodes
		 * 
		 * @return A span over the child nodes
		 */
		std::span<Node> getChildNodes();

		/**
		 * @brief Get the child nodes
		 *
		 * @return A span over the child nodes
		 */
		std::span<const Node> getChildNodes() const;

	private:
		const TIdentifier id; ///< The node's identifier
		ChildContainer childNodes; ///< The node's child nodes

	};

}

#include <libcpplog/utils/tree/Node.tpp>