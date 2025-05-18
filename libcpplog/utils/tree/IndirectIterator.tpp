#include <libcpplog/utils/tree/IndirectIterator.hpp>

namespace cpplog::utils::tree {

    template <typename TBaseIterator>
    IndirectIterator<TBaseIterator>::IndirectIterator(const TBaseIterator& other) 
        : TBaseIterator(other) {
    
    }

    /**
     * @brief Overload for dereference operator
     * 
     * @details
     * Dereference twice to dereference the unique pointer and get the value
     */
    template <typename TBaseIterator>
    IndirectIterator<TBaseIterator>::reference IndirectIterator<TBaseIterator>::operator*() const {
        return *(this->TBaseIterator::operator*());
    }

    /**
     * @brief Overload for arrow operator
     * 
     * @details
     * Arrow operator follows special semantics, applying itself until it reaches a 
     * raw pointer.
     */
    template <typename TBaseIterator>
    IndirectIterator<TBaseIterator>::pointer IndirectIterator<TBaseIterator>::operator->() const {
        return this->TBaseIterator::operator*().get();
    }

}