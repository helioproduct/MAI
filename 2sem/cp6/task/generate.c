#include <stdio.h>
#include <stdlib.h>

#include "io.c"

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

    Student s;
    while (student_read_txt(&s, in)) {
        student_write_bin(&s, out);
    }

    fclose(out);
    fclose(in);

    return 0;
}