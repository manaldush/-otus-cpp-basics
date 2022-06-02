#include "iostream"
#include "containers.hpp"

template<typename T>
class Entry {
    public:
        Entry(const T* _val) : val {_val}, next {nullptr} {}

        ~Entry() {
            delete val;
        }

        Entry<T>* getNext() {
            return next;
        }

        void setNext(Entry<T>* _next) {
            next = _next;
        }

        const T* getVal() {
            return val;
        }
    private:
        const T* val;
        Entry<T>* next;
};

template<typename T>
class ListExt : public IContainer<T> {
    public:
        ListExt();

        ~ListExt();

        void push_back(const T* var) override;

        void insert(const T* var, std::size_t index = 0) override;

        void erase(std::size_t index = 0) override;

        std::size_t size() const override;

        const T& operator[](std::size_t idx) const override;

        std::string name() const override;

        std::ostream& operator<<(std::ostream& os) const override;

    private:
        Entry<T>* head;
        std::size_t length;

        Entry<T>* getPrev(std::size_t index) const {
            Entry<T>* prev = head;
            if (prev == nullptr || length <= index || index == 0) {
                prev = nullptr;
            } else {
                std::size_t prevIndex = 0;
                while(++prevIndex < index) {
                    prev = prev->getNext();
                }
            }

            return prev;
        }
};

template<typename T>
ListExt<T>::ListExt() : head{nullptr}, length{0} {}

template<typename T>
ListExt<T>::~ListExt(){
    std::cout << "ListExt::destructor call" << std::endl;
    Entry<T>* next = head;
    while(next != nullptr) {
        Entry<T>* cur = next;
        next = cur->getNext();
        delete cur;
    }
}

template<typename T>
void ListExt<T>::push_back(const T* var) {
    if (head == nullptr) {
        head = new Entry<T>(var);
        ++length;
    } else {
        Entry<T>* last = head;
        while(last->getNext() != nullptr) {
            last = last->getNext();
        }
        last->setNext(new Entry<T>(var));
        ++length;
    }
}

template<typename T>
void ListExt<T>::insert(const T* _val, std::size_t index) {
    if (length <= index) {
        std::cerr << "Illegal index" << std::endl;
        exit(1);
    } else if (head == nullptr) {
        head = new Entry<T>(_val);
        length++;
    } else if (index == 0) {
        // set as first element of not empty list
        Entry<T>* prev = head;
        head = new Entry<T>(_val);
        head->setNext(prev);
        ++length;
    } else if (index == length) {
        // set as last element of not empty list
        this->push_back(_val);
    } else {
        // case when index is between two elements
        Entry<T>* prev = getPrev(index);
        Entry<T>* entry = new Entry<T>(_val);
        Entry<T>* next = prev->getNext();
        prev->setNext(entry);
        entry->setNext(next);
        ++length;
    }
}

template<typename T>
void ListExt<T>::erase(std::size_t index) {
    if (head == nullptr || index >= length) {
        std::cerr << "Illegal index" << std::endl;
        exit(1);
    } else if (index == 0) {
        Entry<T>* cur = head;
        head = head->getNext();
        delete cur;
        --length;
    } else {
        Entry<T>* prev = getPrev(index);
        Entry<T>* cur = prev->getNext();
        prev->setNext(cur->getNext());
        --length;
        delete cur;
    }
}

template<typename T>
std::size_t ListExt<T>::size() const {
    return length;
}

template<typename T>
const T& ListExt<T>::operator[](std::size_t index) const {
    if (index >= length || head == nullptr) {
        std::cerr << "Illegal index" << std::endl;
        exit(1);
    }

    Entry<T>* prev = getPrev(index);
    return prev == nullptr ? *(head->getVal()) : *(prev->getNext()->getVal());
    //return null;
}

template<typename T>
std::string ListExt<T>::name() const {
    return "List";
}

template<typename T>
std::ostream& ListExt<T>::operator<<(std::ostream& os) const {
    os << name()<< "[";
    Entry<T>* entry = head;
    while(entry != nullptr) {
        os << " " << (*entry->getVal()) ;
        entry = entry->getNext();
    }
    os << " ]" << std::endl;
    return os;
}