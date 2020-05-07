#include <iostream>

#include "list.h"
#include <vector>

void print_list(list<int> &list)
{
    std::cout << list;

    for (auto node: list)
    {
        std::cout << node.get() << "\n";
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
    auto end = list3.begin() + 4;
    list<int> list6(fst, end);
    print_list(list6);

    // Тест виртуальных методов
    std::cout << "\nIs empty method: ";
    std::cout << "Is empty (list6): " << list6.is_empty();

    std::cout << "\nAfter clear method: ";
    list6.clear();
    std::cout << "Is empty (list6): " << list6.is_empty();

    try
    {
        list6.pop_back();
    } catch (empty_list &error) {
        std::cout << error.what();
    }

    try
    {
        list<int> list20(arr, -1);
    } catch (size_error &error) {
        std::cout << error.what();
    }

    // Тест push_front методов
    std::cout << "\nPush front by value: ";
    auto iterator = list6.push_front(6);

    while (iterator != list6.end())
    {
        std::cout << " " << (*iterator).get();
        iterator++;
    }

    print_list(list6);

    std::cout << "\nPush front by list (list3): ";
    list6.push_front(list3);
    print_list(list6);

    // Тест insert методов
    list<int> list7 = { 1, 2, 3 };

    std::cout << "\nInsert value to 1st pos: ";
    list7.insert(list7.begin() + 1, 4);
    print_list(list7);

    std::cout << "\nInsert list (list3) to 2nd pos: ";
    list7.insert(list7.begin() + 2, list3);
    print_list(list7);

    std::cout << "\nInsert (const interator) value to 1st pos: ";
    list7.insert(list7.cbegin() + 1, 4);
    print_list(list7);

    std::cout << "\nInsert (const iterator) list (list3) to 2nd pos: ";
    list7.insert(list7.cbegin() + 2, list3);
    print_list(list7);

    // Test push_back методов
    list<int> list8 = { 1, 2, 3 };
    std::cout << "\nPush back by value: ";
    list8.push_back(4);
    print_list(list8);

    std::cout << "\nPush back by list (list3): ";
    list8.push_back(list3);
    print_list(list8);

    // Тест pop методов
    std::cout << "\nPop front (list8): ";
    list8.pop_front();
    print_list(list8);

    std::cout << "\nPop back (list8): ";
    list8.pop_back();
    print_list(list8);

    std::cout << "\nRemove by iterator (pos 2): ";
    list8.remove(list8.begin() + 2);
    print_list(list8);

    // Тест reverse
    std::cout << "\nReverse list (list3): ";
    list3.reverse();
    print_list(list3);

    // Тест операторов

    list<int> list9 = { 1, 2, 3 };
    list<int> list10 = { 1, 2, 3 };

    std::cout << "\nTest == operator: ";
    if (list9 == list10)
    {
        std::cout << "done";
    }
    else
    {
        std::cout << "failed";
    }

    list9.pop_back();

    std::cout << "\nTest != operator: ";
    if (list9 != list10)
    {
        std::cout << "done";
    }
    else
    {
        std::cout << "failed";
    }

    std::cout << "\nTest = operator: ";
    list9 = list10;
    print_list(list9);

    std::cout << "\nTest += operator: ";
    list9 += list10;
    list9 += 25;
    print_list(list9);

    std::cout << "\nTest + operator: ";
    list9 = list10 + list8 + list9;
    list9 += 777;
    print_list(list9);

    // Тест итераторов
    std::cout << "\nTest iterators: ";
    auto iterator1 = list9.begin();
    //*iterator1 = 500;
    //*(++iterator1 + 1) = 400;
    print_list(list9);

    std::cout << "\nTest constant iterators: ";
    auto iterator2 = list9.cbegin();
    // *iterator2 = 522; - не должно работать
    ++iterator2++;
    auto iterator3 = list9.cend();

    while (++iterator2 != iterator3)
    {
        std::cout << (*iterator2).get() << " ";
    }

    list<int> list11 = { 1, 2, 3 };
    list<int> list12 = { 4, 5, 6 };

    // Тест merge метода
    std::cout << "\nMerge test: ";
    list12.merge(list11);
    list12.merge(505);
    print_list(list12);

    // Тест bool оператора
    std::cout << "\nBool operators test (not constant): ";
    if (list11.begin())
    {
        std::cout << "test1 done ";
    }
    else
    {
        std::cout << "test1 fail ";
    }

    if (list11.end())
    {
        std::cout << "test2 fail";
    }
    else
    {
        std::cout << "test2 done";
    }

    std::cout << "\nBool operators test (constant): ";
    if (list11.cbegin())
    {
        std::cout << "test1 done ";
    }
    else
    {
        std::cout << "test1 fail ";
    }

    if (list11.cend())
    {
        std::cout << "test2 fail";
    }
    else
    {
        std::cout << "test2 done";
    }

    return 0;
}
