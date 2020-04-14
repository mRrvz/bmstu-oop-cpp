#include <iostream>

#include "list.h"

int main(void)
{
    setbuf(stdout, NULL);

    list<int> list1 = { 1, 2, 7, 12, 14 };
    auto t = list1.begin();
    auto x = list1.end();
    list<int> list2(t, x);

    //list_iterator<list_node<int>> iter = list2.begin();
    auto xs = list2.begin();
    auto y = list2.end();


    for (auto i: list2)
    {
        std::cout << i << "\n";
}

    std::cout << "ASSALAM\n";
    std::cout << list2.get_size() << list2.is_empty();
    std::cout << "\n\n\n";


    return 0;
}
