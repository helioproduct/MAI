#include <stdio.h>
#include <stdbool.h>

bool is_digit(char c)
{
    return '0' <= c && c <= '9' || c == 'A';
}

void print_number(char number[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%c", number[i]);
    }
    printf("\n");
}

// Вариант 11
int main()
{
    FILE *file;
    file = fopen("input.txt", "r");
    char c;

    char number[11];
    int len = 0;

    enum State {
        START,
        SEARCH_DIGIT,
        NUMBER,
        SKIP_NUMBER,
        FINISH,
    } state = START;

    while (state != FINISH)
    {
        switch (state)
        {
        case START:
            state = SEARCH_DIGIT;
            break;
        
        case SEARCH_DIGIT:
            c = getc(file);
            if (c == EOF)
            {
                state = FINISH;
            } 
            if (is_digit(c))
            {
                number[len] = c;
                len++;
                state = NUMBER;
            }
            break;

        case NUMBER:
            c = getc(file);
            if (c == EOF)
            {
                state = FINISH;
                print_number(number, len);
            }
            else if (is_digit(c))
            {
                if (number[len - 1] < c)
                {
                    number[len++] = c;
                }
                else 
                {
                    len = 0;
                    state = SKIP_NUMBER;  
                }
                break;
            }
            else
            {
                print_number(number, len);
                len = 0;
                state = SEARCH_DIGIT;
            }
            break;

        case SKIP_NUMBER:
            c = getc(file);
            if (c == EOF)
            {
                state = FINISH;
            }
            if (!is_digit(c))
            {
                state = SEARCH_DIGIT; 
            }
            else
            {
                state = SKIP_NUMBER;
            }
            break;
        }
    }
    fclose(file);
}