#pragma once

namespace cpplog::utils::tree {

    /**
	 * @brief An indirect iterator intended for use with a container of smart pointers
     * 
     * This iterator is based on the `boost`'s library `indirect_iterator`.
	 * It allows traversing containers of smart pointers as if they were containers of values.
     * 
     * @details
     * It solves the problem of returning a reference to a container of unique pointers to clients,
     * which is problematic because:
     * - clients could move objects out of the referenced containers
     * - implementation detail (unique_ptr used) is leaked to client
     */
    template <typename TBaseIterator> 
    class IndirectIterator : public TBaseIterator {

    public:
        /// @brief The type of the element inside the iterated container
        using value_type = typename TBaseIterator::value_type::element_type;
        using pointer = value_type*; ///< pointer to element type
        using reference = value_type&; ///< reference to element type

        /**
         * @brief Default constructor
         * 
         * @details
         * `std` iterators are default constructible and we want to keep standard 
         * semantics.
         */
		IndirectIterator() = default;

        /**
         * @brief Constructor
         * 
         * @param[in] other The base iterator of the underlying container
         */
        IndirectIterator(const TBaseIterator& other);

        /**
         * @brief Overload for dereference operator
         */
        reference operator*() const;

        /**
		 * @brief Overload for arrow operator
         * 
         * @details
         * Arrow operator follows special semantics, applying itself until it reaches a 
         * raw pointer.
         */
        pointer operator->() const;
    };

}

#include <libcpplog/utils/tree/IndirectIterator.tpp>