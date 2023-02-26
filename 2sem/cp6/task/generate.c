#include <stdio.h>
#include <stdlib.h>
#include "io.c"
#include <time.h>


int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("Usage: %s SOURCE_FILE DB_FILE\n", argv[0]);
        exit(0);
    }

    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");

    if (!in || !out) {
        printf("I/O Error: Can't open file.\n");
        exit(1);
    }

    time_t start = time(NULL);

    Student s;
    while (student_read_txt(&s, in)) {
        student_write_bin(&s, out);
    }
    
    time_t finish = time(NULL);
    printf("generated in %ld seconds\n", finish - start);


    fclose(out);
    fclose(in);

    return 0;
}