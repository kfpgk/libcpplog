#pragma once

namespace cpplog::utils::tree::unit_test {

	/**
	 * @brief Unit test for the Node class
	 */
	class NodeTest {

	public:
		/**
		 * @brief Test the `getId()` method
		 */
		void testGetId() const;

		/**
		 * @brief Test adding child nodes by copying
		 */
		void testAddingChildNodesCopy() const;

		/**
		 * @brief Test adding child nodes by moving
		 */
		void testAddingChildNodesMove() const;

		/**
		 * @brief Test iterating over the child nodes via a range-based foor loop
		 */
		void testIteratingRangeBased() const;

		/**
		 * @brief Test iterating over the child nodes via `getChildNodes()` method
		 */
		void testIteratingChildNodes() const;
	};

}