#include <stdio.h>

int main()
{
    FILE *file;
    file = fopen("program.pas", "r");
    
    char c;
    int words = 0;

    enum State {
        START,
        SEARCH_COMMENT,
        SLASH,
        ONE_LINE_COMMENT,
        MULTI_LINE_COMMENT,
        WORD_IN_ONE_LINE_COMMENT,
        WORD_IN_MULTI_LINE_COMMENT,
        FINISH
    } state = START;

    while (state != FINISH)
    {
        switch (state)
        {
        case START:
            state = SEARCH_COMMENT;
            break;
        
        case SEARCH_COMMENT:
            c = getc(file);
            if (c == EOF)
                state = FINISH;
            else if (c == '/')
                state = SLASH;
            else if (c == '{')
                state = MULTI_LINE_COMMENT;
            break;
        
        case SLASH:
            c = getc(file);
            if (c == EOF)
                state = FINISH;
            else if (c == '\n')
                state = SEARCH_COMMENT;
            else if (c == '/')
                state = ONE_LINE_COMMENT;
            break;

        case ONE_LINE_COMMENT:
            c = getc(file);
            if (c == EOF)
                state = FINISH;
            else if (c != ' ' && c != '\n' && c != ',' && c != '\t')
            {
                state = WORD_IN_ONE_LINE_COMMENT;
                words++;
            }
            else if (c == '\n')
                state = SEARCH_COMMENT;
            break;   

        case WORD_IN_ONE_LINE_COMMENT:
            c = getc(file);
            if (c == EOF)
                state = FINISH;
            if (c == ' ' || c == '\n' || c == ',' || c == '\t')
            {
                state = ONE_LINE_COMMENT;
            }
            break;

        case MULTI_LINE_COMMENT:
            c = getc(file);
            if (c == EOF)
                state = FINISH;
            else if (c != ' ' && c != '\n' && c != ',' && c != '\t' && c != '}')
            {
                state = WORD_IN_MULTI_LINE_COMMENT;
                words++;
            }
            else if (c == '}')
                state = SEARCH_COMMENT;
            break;

        case WORD_IN_MULTI_LINE_COMMENT:
            c = getc(file);
            if (c == EOF)
                state = FINISH;
            if (c == ' ' || c == '\n' || c == ',' || c == '\t')
                state = MULTI_LINE_COMMENT;
            break;
        }  
    }   
    printf("%d", words);
}