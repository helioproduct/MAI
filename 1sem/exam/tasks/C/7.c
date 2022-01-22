#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Сложность: O(1)
char get_reversed_byte(char number)
{
    char reversed_byte = 0;
    for (int i = 0; i < CHAR_BIT; i++)
    {
        int bit = (number >> i) & 1;
        reversed_byte |= bit << CHAR_BIT - 1 - i;
    }     
    return reversed_byte;
}

int main(void)
{
    char number;
    scanf("%d", &number);
    printf("%d", get_reversed_byte(number));   
    return 0;
}