#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include "io.h"


void student_print(Student *s)
{
    printf("%s %s %c %s ", s->surname, s->initials, s->gender, s->group);
    printf("%hu %hu %hu %hu\n", s->la, s->ma, s->dm, s->cs);
}


int student_write_txt(Student *s, FILE *in)
{
    int chars_written = 0;
    chars_written += fprintf(in, "%s %s %c %s ", s->surname,
                                                 s->initials,
                                                 s->gender,
                                                s->group);
    chars_written += fprintf(in, "%hu %hu %hu %hu\n", s->la,
                                                      s->ma,
                                                      s->dm, 
                                                      s->cs);
    return chars_written;
}


int student_write_bin(Student *s, FILE *out)
{
    return fwrite(s, sizeof(Student), 1, out);
}


int student_read_txt(Student *s, FILE *in)
{ 
    fscanf(in, "%s %s %c %s", s->surname, s->initials, &s->gender, &s->group);
    fscanf(in, "%hu %hu %hu %hu", &s->la, &s->ma, &s->dm, &s->cs);
    return !feof(in);
}


int student_read_bin(Student *s, FILE *in) 
{
    return fread(s, sizeof(Student), 1, in);
}


bool remove_student(char *db_path, Student *record_to_remove)
{
    FILE *source = fopen(db_path, "r");
	FILE *temp_storage = fopen("temp.bin", "a");

	Student record;

	while (student_read_bin(&record, source)) {
		if (!is_equal(&record, record_to_remove)) {
            student_write_bin(&record, temp_storage); 
        }
	}

	fclose(source);
	fclose(temp_storage);
	rename("temp.bin", db_path);
}