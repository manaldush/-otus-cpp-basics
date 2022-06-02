#include "containers.hpp"

template<typename T>
Iterator<T>::Iterator(const IContainer<T>& _container, std::size_t _index) : container{_container}, index{_index} {}

template<typename T>
Iterator<T>& Iterator<T>::operator++() {
    std::size_t nextIndex = index + 1;
    if (nextIndex > this->container.size() || this->container.size() == 0 && nextIndex == 0) {
        std::cerr << "Invalid iteration opeartion" << std::endl;
        exit(1);
    }
    index = nextIndex;
    return *this;
}

template<typename T>
const T& Iterator<T>::get() const {
    return this->container[index];
}

template<typename T>
bool Iterator<T>::operator==(const Iterator<T>& other) const {
    return (&other == this) ||
            (&(this->container) == &(other.container) && this->index == other.index);
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T>& other) const {
    return !this->operator==(other);
}