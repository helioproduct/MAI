#include "utils.h"
#include <stdlib.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

void move(struct Dot *dot, int k)
{
    int i = (*dot).i;
    int j = (*dot).j;
    int l = (*dot).l;  

    (*dot).i = abs(pow(i, 3) - pow(j, 3) + pow(l, 3) - k) % 20;
    (*dot).j = abs(min(min(i*j*k - k, i*i*l - k), j*l*l - k)) % 30;
    (*dot).l = abs(max(max(i*j*j - k, i*i*l - k), j*l*l - k)) % 30;
}

bool in_circle(struct Dot dot, int x, int y, int R)
{
    return pow(dot.i - x, 2) + pow(dot.j - y, 2) <= pow(R, 2);
}

bool in_area(struct Dot dot)
{
    return in_circle(dot, -10, -10, 10) && in_circle(dot, 10, 10, 10);
}
