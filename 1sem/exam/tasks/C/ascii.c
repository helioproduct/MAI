#include <stdio.h>

int main()
{
    for (int i = 32; i < 128; i++)
    {
        printf("%d-%c  ", i, i);
        if (i % 10 == 0)
            printf("\n\n");
    }
}