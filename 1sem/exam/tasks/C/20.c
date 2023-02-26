#include <stdio.h>
#include <limits.h>

void print_byte(char byte)
{
    for (int i = CHAR_BIT - 1; i >= 0; i--)
    {
        char bit = byte >> i & 1;
        printf("%d", bit);
    }
    printf("\n");
}

//  1 1 0 0 0 0 0 0 0

int main(void)
{
    char byte;
    scanf("%d", &byte);
    print_byte(byte);
}