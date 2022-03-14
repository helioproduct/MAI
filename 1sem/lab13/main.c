#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// 1065233
const unsigned int english_vowels = 1u << ('a'-'a') |
                                    1u << ('e'-'a') |
                                    1u << ('i'-'a') |
                                    1u << ('o'-'a') |
                                    1u << ('u'-'a');

unsigned int char_to_set(char c)
{
    c = tolower(c);
    if (c < 'a' || c > 'z')
    {
        return 0;
    }
    return 1u << (c - 'a');
}

// Есть ли слово, хотя бы одна гласная которого повторяется [Вариант 3]

int main()
{
    char c;
    unsigned int current_char_set = 0;
    unsigned int word_faced_vowels;

    FILE *f = fopen("source.txt", "r");
    
    while ((c = fgetc(f)) != EOF)
    {
        if (c == '\n' || c == ' ')
        {
            word_faced_vowels = 0;
            continue;
        }

        current_char_set = char_to_set(c);

        if ((current_char_set & english_vowels) != 0)
        {   
            if ((current_char_set & word_faced_vowels) != 0)
            {
                printf("YES");
                return 0;
            }
            word_faced_vowels = word_faced_vowels | current_char_set;
        }
    }

    printf("NO");

    fclose(f);

    return 0;   
}
