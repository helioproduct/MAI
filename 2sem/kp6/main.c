#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#include "student.h"
#include "io.c"

typedef struct {
    double avg_mark;
    int group;
} StudentStat;

double avg_mark(Student *s)
{
    int sum = s->cs + s->dm + s->la + s->ma + s->hi;
    return sum / 5.0;    
}

/*
    Выяснить, в какой группе учится максимальное
    число студентов с минимальным на 
    курсе средним баллом.
*/
int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage:\n\t ./main DB_FILE\n");
    }

    FILE *in = fopen(argv[1], "r");

    if (!in) {
        printf("I/O Error: can't open file.\n");
        exit(1);
    }

    double avg = 0.0;
    double min_avg = DBL_MAX;

    StudentStat students[200] = { { 0.0, -1 }};
    int students_qty = 0.0;

    // Группы с минимальным средним баллом
    int min_avg_groups[200] = {-1};
    int min_avg_groups_qty = 0;

    Student student;

    while (student_read_bin(&student, in)) {
        avg = avg_mark(&student);
        if (avg <= min_avg) {
            min_avg = avg;
        }
        students[students_qty++] = (StudentStat) {avg, student.group};
    }

    for (int i = 0; i < students_qty; ++i) {
        if (students[i].avg_mark == min_avg) {
            min_avg_groups[min_avg_groups_qty++] = students[i].group;
        }
    }

    // sort_array

    int max_gap = -1;
    int max_idx = -1;
    int gap = 0;
    int prev = min_avg_groups[0];   

    for (int i = 0; i < min_avg_groups_qty; ++i) {
        if (min_avg_groups[i] == prev) {
            ++gap;
        } else if (gap > max_gap) {
            max_gap = gap;
            max_idx = i - 1;
        }
    }

    if (gap > max_gap) {
        max_gap = gap;
        max_idx = min_avg_groups_qty - 1;
    }

    if (max_idx >= 0) {
        printf("%d", min_avg_groups[max_idx]);
    }

    return 0;
}
