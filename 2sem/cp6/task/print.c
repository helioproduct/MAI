#include <stdio.h>
#include <stdlib.h>

#include "io.c"

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: %s DB_FILE\n", argv[0]);
        exit(0);
    }

    FILE *in = fopen(argv[1], "r");

    if (!in) {
        printf("I/O Error: Can't open file.\n");
        exit(1);
    }

    Student s;
    while (student_read_bin(&s, in)) {
        student_print(&s);
    }

    return 0;
}