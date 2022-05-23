#ifndef IO
#define IO

#include "student.h"

int student_read_txt(Student *s, FILE *in);
int student_read_bin(Student *s, FILE *in);
void student_write_bin(Student *s, FILE *out);
int student_print(Student *s, FILE *out);

#endif // IO