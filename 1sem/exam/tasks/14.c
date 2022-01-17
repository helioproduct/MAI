#include <stdio.h>

// Сложность: O(1)
// Реверс машинного слова
int get_reversed_word(int word)
{
    int reversed_word = 0;
    const int int_size = sizeof(int) * 8;
    for (int shift = int_size - 1; shift >= 0; shift--)
    {
        int bit = word >> shift & 1;           
        reversed_word |=  bit << int_size - 1 - shift;
    }        
    return reversed_word;
}

int main(void)
{
    int machine_word;
    scanf("%d", &machine_word);
    printf("%d", get_reversed_word(machine_word));
}