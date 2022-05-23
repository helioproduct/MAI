#include <stdio.h>
#include <stdlib.h>

#include "student.h"
#include "io.h"

int student_read_txt(Student *s, FILE *in)
{
    fscanf(in, "%s", s->surname);
    fscanf(in, "%s", &(s->initials));
    fscanf(in, "%c", &(s->gender));
    fscanf(in, "%c", &(s->group));
    
    fscanf(in, "%c", &(s->dm));
    fscanf(in, "%c", &(s->ma));
    fscanf(in, "%c", &(s->la));
    fscanf(in, "%c", &(s->cs));
    fscanf(in, "%c", &(s->hi));

    return !feof(in);
}

int student_read_bin(Student *s, FILE *in)
{
    fread(s->surname, sizeof(char), STR_SIZE, in);
    fread(s->initials, sizeof(char), STR_SIZE, in);
    fread(&(s->gender), sizeof(char), 1, in);
    fread(&(s->group), sizeof(int), 1, in);
    
    fread(&(s->dm), sizeof(int), 1, in);
    fread(&(s->ma), sizeof(int), 1, in);
    fread(&(s->la), sizeof(int), 1, in);
    fread(&(s->cs), sizeof(int), 1, in);
    fread(&(s->hi), sizeof(int), 1, in);

    return !feof(in);
}

void student_write_bin(Student *s, FILE *out)
{
    fwrite(s->surname, sizeof(char), STR_SIZE, out);
    fwrite(s->initials, sizeof(char), STR_SIZE, out);
    fwrite(&(s->gender), sizeof(char), 1, out);
    fwrite(&(s->group), sizeof(int), 1, out);
    
    fwrite(&(s->dm), sizeof(int), 1, out);
    fwrite(&(s->ma), sizeof(int), 1, out);
    fwrite(&(s->la), sizeof(int), 1, out);
    fwrite(&(s->cs), sizeof(int), 1, out);
    fwrite(&(s->hi), sizeof(int), 1, out);
}