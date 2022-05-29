#ifndef STUDENT
#define STUDENT

#include <stdbool.h>
#include <string.h>

#define STR_SIZE 24

typedef struct {
    char surname[STR_SIZE];
    char initials[STR_SIZE];
    char gender;
    char group[STR_SIZE];
    unsigned short la, ma, dm, cs;
} Student;


double avg_mark(Student *s)
{
    return (s->la + s->ma + s->dm + s->cs) / 4.0;
}

bool is_equal(Student *a, Student *b)
{

    return strcmp(a->surname, b->surname) == 0 &&
           strcmp(a->initials, b->initials) == 0 && 
           strcmp(a->group, b->group) == 0 &&
           a->gender == b->gender &&
           a->la == b->la &&
           a->ma == b->ma &&
           a->dm == b->dm &&
           a->cs == b->cs;
}


int sortstring(const void *str1, const void *str2)
{
    char *const *pp1 = str1;
    char *const *pp2 = str2;
    return strcmp(*pp1, *pp2);
}


#endif
