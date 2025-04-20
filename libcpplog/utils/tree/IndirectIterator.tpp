#include <libcpplog/utils/tree/IndirectIterator.hpp>

namespace cpplog::utils::tree {

    template <typename TBaseIterator>
    IndirectIterator<TBaseIterator>::IndirectIterator(const TBaseIterator& other) 
        : TBaseIterator(other) {
    
    }

    template <typename TBaseIterator>
    IndirectIterator<TBaseIterator>::reference IndirectIterator<TBaseIterator>::operator*() const {
        return *(this->TBaseIterator::operator*());
    }

    template <typename TBaseIterator>
    IndirectIterator<TBaseIterator>::pointer IndirectIterator<TBaseIterator>::operator->() const {
        return this->TBaseIterator::operator*().get();
    }

}