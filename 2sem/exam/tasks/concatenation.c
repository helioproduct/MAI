#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 4) {
        printf("Usage: %s file1 file2 file3\n", argv[0]);
        return 0;
    }

    FILE *file1 = fopen(argv[1], "r");
    FILE *file2 = fopen(argv[2], "r");
    FILE *file3 = fopen(argv[3], "r");

    FILE *result = fopen("result.txt", "w");

    char c = '\0';

    while ( (c = getc(file1)) != EOF)
        fputc(c, result);

    while ( (c = getc(file2)) != EOF)
        fputc(c, result);

    while ( (c = getc(file3)) != EOF)
        fputc(c, result);

    fclose(result);
    fclose(file1);
    fclose(file2);
    fclose(file3);

    return 0;
}