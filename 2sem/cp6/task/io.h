#ifndef IO
#define IO

#include <stdio.h>
#include <stdbool.h>
#include "student.h"

int student_read_txt(Student *s, FILE *out);
int student_read_bin(Student *s, FILE *in);

int student_write_txt(Student *s, FILE *out);
int student_write_bin(Student *s, FILE *in);

void student_print(Student *s);

#endif