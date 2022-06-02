#pragma once

#include <iostream>

template<typename T> class Iterator;


template<typename T>
class IContainer {
    public:
        virtual ~IContainer() {}

        virtual void push_back(const T* var) = 0;

        virtual void insert(const T* var, std::size_t index = 0) = 0;

        virtual void erase(std::size_t index = 0) = 0;

        virtual std::size_t size() const = 0;

        virtual const T& operator[](std::size_t idx) const = 0;

        virtual std::string name() const = 0;

        virtual std::ostream& operator<<(std::ostream& os) const = 0;

        const Iterator<T> begin() const;

        const Iterator<T> end() const;
};

template<typename T>
class Iterator {
    public:
        Iterator(const IContainer<T>& _container, std::size_t _index);
        Iterator<T>& operator++() ;
        const T& get() const;
        bool operator!=(const Iterator<T>& other) const;
        bool operator==(const Iterator<T>& other) const;
    private:
        const IContainer<T>& container;
        std::size_t index;
};

template<typename T>
const Iterator<T> IContainer<T>::begin() const {
    return Iterator<T>::Iterator(*this, 0);
}

template<typename T>
const Iterator<T> IContainer<T>::end() const {
    return Iterator<T>::Iterator(*this, this->size());
}