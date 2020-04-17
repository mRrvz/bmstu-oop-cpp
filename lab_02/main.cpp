#include <iostream>

#include "list.h"
#include <vector>

void print_list(list<int> &list)
{
    for (auto node: list)
    {
        std::cout << node << " ";
    }
}

int main(void)
{
    setbuf(stdout, NULL);

    // Тест кострукторов
    std::cout << "Constructor 1 test: ";
    list<int> list1;

    std::cout << "\nConstructor 2 test: ";
    list<int> list2;

    std::cout << "\nConstructor 3 test: ";
    int arr[] = { 5, 4, 3, 2, 1 };
    list<int> list3(arr, 5);
    print_list(list3);

    std::cout << "\nConstructor 4 test: ";
    list<int> list4(list3);
    print_list(list4);

    std::cout << "\nConstructor 5 test: ";
    list<int> list5 = { 5, 4, 3, 2, 1 };
    print_list(list5);

    std::cout << "\nConstructor 6 test: ";
    auto fst = list3.begin();
    auto end = list3.end();
    list<int> list6(fst, end);
    print_list(list6);

    // Тест виртуальных методов
    std::cout << "\nVirtual methods: ";
    std::cout << list6.is_empty() << " " << list6.get_size();

    // Тест push_front методов
    std::cout << "\nPush front methods: ";
    list6.push_front(6);

    std::shared_ptr<list_node<int>> node(new list_node<int>);
    node->set(7);
    list6.push_front(node);

    list<int> list7 = { 10, 9, 8, 7, 6, 5 };
    list6.push_front(list7);
    //list6.insert(list6.begin() + 2, 1);
    //list6.insert(list6.begin(), 999);

    print_list(list6);
    std::cout << "\nReverse: ";
    print_list(list6);

    list<int> list8 = { 1, 2, 3, 4, 5, 6, 7, 8 };
    list<int> list9 = { 999, 228, 400 };
    //auto x = list8.begin();
    list8.insert(list8.cbegin() + 2, list9);
    //list8.remove(list8.begin() + 2);
    //vec.insert(vec.cbegin(), 228);
    //auto y = vec.begin();

    std::cout << "\napend by list: ";
    print_list(list8);
    std::cout << "\ndelete by lsi: ";
    list8.remove(list8.begin() );
    print_list(list8);


    //list7.push_back(list6);
    return 0;
}
