#pragma once

namespace cpplog::utils::tree::unit_test {

	/**
	 * @brief Unit test for the IndirectIterator class
	 */
	class IndirectIteratorTest {

	public:
		/**
		 * @brief Test construction
		 */
		void testConstruction() const;

		/**
		 * @brief Test increment
		 */
		void testIncrement() const;

		/**
		 * @brief Test decrement
		 */
		void testDecrement() const;

		/**
		 * @brief Test not equal comparison
		 * 
		 * @details
		 * Equal comparison is tested with the increment and decrement tests.
		 */
		void testNotEqualComparison() const;

		/**
		 * @brief Test dereference operator
		 */
		void testDereferenceOperator() const;

		/**
		 * @brief Test arrow operator
		 */
		void testArrowOperator() const;

		/**
		 * @brief Test reaching end of container
		 */
		void testEndOfContainer() const;

		/**
		 * @brief Test range based for loop
		 */
		void testRangeBasedForLoop() const;
	};



}
