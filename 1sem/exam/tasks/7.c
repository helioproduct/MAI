#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Сложность: O(1)
int get_reversed_byte(int number)
{
    int reversed_byte = 0;
    for (int shift = 7; shift >= 0; shift--)
    {
        int bit = number >> shift & 1;           
        reversed_byte |=  bit << 7 - shift;
    }        
    return reversed_byte;
}


int main(void)
{
    int number;
    scanf("%d", &number);
    printf("%d", get_reversed_byte(number));   
    return 0;
}