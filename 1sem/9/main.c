#include <stdio.h>
#include "dot.c"
#include "utils.c"

// Центр первого круга: (-10, -10); Радиус = 10;
// Центр второго круга: (-20, -20); Радиус = 10;

int main()
{  
    struct Dot dot = {.i = 7, .j = 27, .l = -10};
    int k = 1;

    while (k <= 50 && !in_area(dot))
    {
        move(&dot, k);
        k++;
    }

    printf("%s ", in_circle(dot, -10, -10, 10) && in_circle(dot, -20, -20, 10) ? "In" : "Out");
    printf("k = %d i = %d j = %d l = %d", k, dot.i, dot.j, dot.l);

    return 0;
}
