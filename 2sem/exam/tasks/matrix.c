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

    // rename("temp.bin", db_path);
    fclose(source);

    source = fopen(argv[1], "w");

    for (int i = 0; i < n; i++)
    {
        dst = fopen(argv[2], "r"); 
        for (int j = 0; j < m; j += m)
        {
            c = fgetc(dst);
            if (c == ' ' || c == '\n') {
                j -= m;
            } else 
            {
                printf("%c", c);
            }
        }
    }

    return 0;
}