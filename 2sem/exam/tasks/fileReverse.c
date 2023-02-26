#include <stdio.h>
#include <stdlib.h>


/*
Читаем последовательно файл
1. Сохраняем очередной символ
2. Рекурсивно запускаем функцию reverse_file (символы файла помещаются в стек памяти)
3. Помещаем значение переменной в результирующий файл output
*/

void reverse_file(FILE *input, FILE *output)
{
    char c;
    if (feof(input)) {
        return;
    } else {
        c = fgetc(input);
        reverse_file(input, output);
        fputc(c, output);
    }
}

int main(int argc, char *argv[])
{
    FILE *input, *output;

    input = fopen(argv[1], "r");
    output = fopen(argv[2], "w");

    reverse_file(input, output);

    return 0;
}