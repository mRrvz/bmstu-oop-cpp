#include <iostream>
#include <list>

int main(void)
{
    std::list<int> list {1, 2, 3, 4, 5};

    std::cout << "\n\n\n";

    //std::set<int> set2 { set.begin(), set.end() };

    std::list<int>::iterator iter = list.begin();
    advance(iter, 3);
    std::list<int>::iterator iter2 = list.insert(iter, 10);
    for (auto el: list)
    {
        std::cout << el << "\n";
    }

    for (; iter2 != list.end(); iter2++)
    {
        std::cout << "k3k\n";
    }

    return 0;
}
