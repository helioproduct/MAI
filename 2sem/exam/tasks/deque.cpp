#include <stdio.h>
#include <stdlib.h>


// Для Си: описать методы дека (без реализации)
#include <deque>

int main(void)
{
    std::deque<int> d = {7, 5, 16, 8};
    std::deque<int> d2;

    while (!d.empty()) {
        d2.push_back(d.back());
        d.pop_back();
    }

    return 0;
}