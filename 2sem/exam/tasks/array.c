#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int A[5] = {1, 2, 3, 4, 5};
    int *p = A;

    printf("%d %d\n", sizeof(A), sizeof(p));

    return 0;
}