#include "iostream"
#include "containers.hpp"

template<typename T>
class VectorExt : public IContainer<T>
{
    public:
        VectorExt();

        ~VectorExt();

        void push_back(const T* var) override;

        void insert(const T* var, std::size_t index = 0) override;

        void erase(std::size_t index = 0) override;

        std::size_t size() const override;

        const T& operator[](std::size_t idx) const override;

        std::string name() const override;

        std::ostream& operator<<(std::ostream& os) const override;

        VectorExt<T>& operator=(const VectorExt<T>& other) const;

    private:
        void increaseCapacity() {
            if (nextIndex == capacity) {
                capacity *= 2;
                copy();
            }
        }

        void decreaseCapacity() {
            if (nextIndex <= (capacity / 2) && (capacity / 2) > minCapacity) {
                capacity /= 2;
                copy();
            }
        }

        void copy() {
            T const ** oldData = data;
            data = new const T*[capacity];
            for(std::size_t counter = 0; counter < nextIndex; counter++) {
                data[counter] = oldData[counter];
            }
            delete[] oldData;
        }

    private:

        static const std::size_t minCapacity = 5;

        T const ** data;
        std::size_t capacity;
        std::size_t nextIndex;
};

template<typename T>
VectorExt<T>::VectorExt() : data{new const T*[VectorExt::minCapacity]}, capacity{VectorExt::minCapacity}, nextIndex{0} {}


template<typename T>
VectorExt<T>::~VectorExt(){
    // delete data array
    std::cout << "VectorExt::destructor call" << std::endl;
    for(size_t i = 0; i < nextIndex; i++) {
        delete data[i];
    }
    delete[] data;
}

template<typename T>
void VectorExt<T>::push_back(const T* var) {
    increaseCapacity();
    data[nextIndex++] = var;
}

template<typename T>
void VectorExt<T>::insert(const T* var, std::size_t index) {
    if (index > nextIndex) {
        std::cerr << "Illegal index" << std::endl;
        exit(1);
    } else if (index == nextIndex) {
        push_back(var);
    } else {
        increaseCapacity();
        std::size_t counter = index;
        const T* prev = nullptr;
        const T* next = var;

        do {
            prev = data[counter];
            data[counter] = next;
            next = prev;
        } while(++counter <= nextIndex);
        ++nextIndex;
    }
}

template<typename T>
void VectorExt<T>::erase(std::size_t index) {
    if (index >= nextIndex) {
        std::cerr << "Illegal index" << std::endl;
        exit(1);
    }

    std::size_t counter = index;
    const T* erasedElement = data[counter];
    while (counter < nextIndex)
    {
        if ((counter + 1) == nextIndex) {
            data[counter] = nullptr;
        } else {
            data[counter] = data[(counter + 1)];
        }
        ++counter;
    }
    nextIndex--;
    delete erasedElement;
    decreaseCapacity();
}

template<typename T>
std::size_t VectorExt<T>::size() const {
    return nextIndex;
}

template<typename T>
const T& VectorExt<T>::operator[](std::size_t idx) const {
    if (idx >= nextIndex) {
        std::cerr << "Illegal index" << std::endl;
        exit(1);
    }

    return *(data[idx]);
}

template<typename T>
std::string VectorExt<T>::name() const {
    return "Vector";
}

template<typename T>
std::ostream& VectorExt<T>::operator<<(std::ostream& os) const {
    os << name() << "[";
    for(std::size_t i = 0; i < nextIndex; i++) {
        os << " " << *(data[i]) ;
    }
    os << " ]" << std::endl;
    return os;
}