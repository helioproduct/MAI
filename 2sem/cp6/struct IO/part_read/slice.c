#include <stdlib.h>
#include <stdio.h>

typedef char Byte;

void parts_write()
{
    FILE *out1 = fopen("1.part", "wb");
    FILE *out2 = fopen("2.part", "wb");

    if (!out1 || !out2) {
        fprintf(stderr, "I/O Error: can't open file\n");
        exit(1);
    }

    int number = 0x1234567;
    Byte *ptr_to_number = (char *) &number;

    fwrite(ptr_to_number + 0,                  sizeof(number) / 2, 1, out1);
    fwrite(ptr_to_number + sizeof(number) / 2, sizeof(number) / 2, 2, out2);

    fclose(out1);
    fclose(out2);
}

void parts_read()
{
    FILE *in1 = fopen("1.part", "rb");
    FILE *in2 = fopen("2.part", "rb");

    if (!in1 || !in2) {
        fprintf(stderr, "I/O Error");
        exit(2);
    }

    int number;
    Byte *ptr_to_number = (char *) &number;

    fread(ptr_to_number + 0,                  sizeof(number) / 2, 1, in1);
    fread(ptr_to_number + sizeof(number) / 2, sizeof(number) / 2, 2, in2);

    fclose(in1);
    fclose(in2);

}

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stdout, "Usage: '%s w' to write, '%s r' to read\n", argv[0], argv[0]);
        exit(0);
    }

    if (argv[1][0] == 'w') {
        parts_write();
    }
    else if (argv[1][0] == 'r') {
        parts_read();
    } 
    else {
        fprintf(stderr, "Usage: '%s w' to write, '%s r' to read\n", argv[0], argv[0]);
    }

    return 0;   
}