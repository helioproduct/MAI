#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("Usage: %s source_file dst_file\n", argv[0]);
        return 0;
    }

    FILE *source = fopen(argv[1], "r");
    FILE *dst = fopen(argv[2], "w");

    if (!source || !dst) {
        printf("I/O Error: Can't open file\n");
        return 0;
    }

    char c;
    int m = 0;
    int n = 0;
    

    while( (c = fgetc(source)) != EOF)
    {
        if (c == '\n') {
            c = ' ';
            n++;
            m = 0;
        }
        else if (c == ' ') {
            m++;
        }
        fputc(c, dst);        
	}
    
    m++;
    n++;

    source = fopen(argv[1], "w");
    dst = fopen(argv[2], "r");

    int i = 0;
    int curr_line = 0;
    int curr_column = 0;

    while(i < m * n)
    {
        c = getc(dst);
        if (c == EOF) 
        {
            dst = fopen(argv[2], "r");
        }
        if (c == ' ') {
            c = fgetc(source);
        }

        if (isdigit(c)) {
            if (i % n == curr_line) {
                fputc(c, source);
                i++;
                fputc(' ', source);
                curr_column++;
            
                if (curr_column == m - 1) {
                    fputc('\n', source);
                    curr_line++;
                }
            }
        } 

	}

    fclose(source);

    return 0;
}