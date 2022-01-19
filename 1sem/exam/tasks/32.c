#include <stdio.h>
#include <stdbool.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

// Сложность: O(n) (из книги Зайцева)
bool is_sorted(char u1[], char u2[], int len1, int len2)
{
    const int max_len = max(len1, len2);
    char w1[max_len];
    char w2[max_len];

    for (int i = 0; i < max_len; i++)
    {
        w1[i] = len1 <= max_len ? u1[i] : ' ';
        w2[i] = len2 <= max_len ? u2[i] : ' ';
    }

    for (int i = 0; i < max_len; i++)
        if (w1[i] > w2[i])
            return false;
    return true;
}

// Лексикографическая упорядоченность последовательности слов 
int main(void)
{  
    // Указатель на последнее слово
    char *word1;
    int len1 = 0;
    // Указатель на предпоследнее слово
    char *word2;
    int len2 = 0;
    // Указатель на текущее слово
    char *current_word = (char*) malloc(0);
    // Последний индекс в слове
    int i = 0;    
    // Текущий символ
    char c;

    bool sorted = true;

    while (scanf("%c", &c) >= 0)
    {   
        // Новое слово
        if (c == ' ' || c == '\n' || c == '\t')
        {
            word2 = word1;
            len2 = len1;
            word1 = current_word;
            len1 = i + 1;
            current_word = (char*) malloc(0);
            i = 0;

            char u2[len1] = &word1;
            char u1[len2] = &word2;

            if (!is_sorted(u2, u1, len2, len1))
                sorted = false;
                printf("NO\N");
                break;
        } else
        {
            // Увеличиваем слово
            current_word = (char*) realloc(current_word, ++i * sizeof(char));
            current_word[i] = c;
        }
    }

    char u1[len1] = &word1;
    char u2[i + 1] = &current_word;

    sorted = is_sorted(u1, u2, len1, i + 1);
    printf(sorted ? "YES" : "NO");

    return 0;
}
