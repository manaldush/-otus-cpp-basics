#include "vectorExt.hpp"
#include "listExt.hpp"
#include "iterator.hpp"

class Element {
    public:
    Element(int _v) : v {_v} {
        //std::cout << "Element constructor call " << v << std::endl;
    }

    ~Element() {
        //std::cout << "Element destructor call " << v << std::endl;
    }
    const int v;
};

std::ostream& operator<<(std::ostream& os, const Element& obj)
{
    os << obj.v;
    return os;
}


template<typename T>
void processContainer(IContainer<T>* container) {
    for(int i = 0; i < 10; i++) {
        container->push_back(new Element(i));
    }
    (*container) << std::cout;

    std::cout << container->name() << " size = " << container->size() << std::endl;
    //удаление третьего (по счёту), пятого и седьмого элементов
    container->erase(2);
    container->erase(3);
    container->erase(4);
    (*container) << std::cout;

    //7. добавление элемента 10 в начало контейнера 
    container->insert(new Element(10), 0);
    (*container) << std::cout;

    //9. добавление элемента 20 в середину контейнера
    container->insert(new Element(20), 4);
    (*container) << std::cout;

    //11. добавление элемента 30 в конец контейнера
    container->push_back(new Element(30));
    (*container) << std::cout;

    // доп задание с итераторами

    std::cout << "Print " << container->name() << " with iterator api" << std::endl;
    for (auto iter = container->begin(); iter != container->end(); ++iter) {
        // или:
        //auto element = iter.get();

        std::cout << "val = " << iter.get() << std::endl;
    }


    delete container;
}

int main() {

    IContainer<Element>* arr[] = {new VectorExt<Element>(), new ListExt<Element>()};

    for (int i = 0; i < 2; i++) {
        std::cout << "---------------------------------------------------------" << std::endl;
        processContainer(arr[i]);
    }

    return 0;
}