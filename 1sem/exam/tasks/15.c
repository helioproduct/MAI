#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Проверка палиндромии машинного слова (int)
// O(1)
int get_reversed_word(int machine_word)
{
    int reversed_word = 0;
    for (int i = 0; i < 32; i++)
    {
        int bit = (machine_word >> i) & 1;
        reversed_word |= bit << 31 - i;
    }
    return reversed_word;
}

bool is_palindrome(int machine_word)
{
    return machine_word == get_reversed_word(machine_word);
}

int main(void)
{
    int machine_word;
    scanf("%d", &machine_word);
    printf(is_palindrome(machine_word) ? "YES" : "NO");
}