#include <float.h>
#include <string.h>
#include <time.h>
#include "student.h"
#include "io.c"
#include <time.h>


typedef struct {
    double avg_mark;
    char group[STR_SIZE];    
} StudentStat;


/*
** Вариант 19
** Выяснить, в какой группе учится максимальное число студентов 
** с минимальным на курсе средни баллом.
*/


int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: %s DB_FILE\n", argv[0]);
        exit(0);
    }

    FILE *source = fopen(argv[1], "r");
    if (!source) {
        printf("I/O Error\n");
        exit(1);
    }

    double avg = 0.0, min_avg = DBL_MAX;
    
    static StudentStat students[50000000] = { {0.0, ""} };
    int students_qty = 0;

    static char* min_avg_groups[50000000] = { "" };
    int min_avg_groups_qty = 0;

    Student student;

    time_t time1 = time(NULL);

    while (student_read_bin(&student, source)) {
        avg = avg_mark(&student);
        if (avg <= min_avg) {
            min_avg = avg;
        }
        StudentStat stat = { avg, ""};
        strcpy(stat.group, student.group);
        students[students_qty++] = stat;
    }
    fclose(source);


    time_t time2 = time(NULL);
    printf("first loop:  %ld seconds\n", time2 - time1);


    time_t time3 = time(NULL);

    for (int i = 0; i < students_qty; i++) {
        if (students[i].avg_mark == min_avg) {
            min_avg_groups[min_avg_groups_qty++] = students[i].group;
        }
    }

    time_t time4 = time(NULL);
    printf("second loop:  %ld seconds\n", time2 - time1);


    time_t time5 = time(NULL);

    qsort(min_avg_groups, min_avg_groups_qty, sizeof(min_avg_groups[0]), sortstring);
    
    time_t time6 = time(NULL);
    printf("qsort:  %ld seconds\n", time2 - time1);


    int max_gap = 0;
    int max_idx = -1;
    int gap = 0;
    char* prev = min_avg_groups[0];

    time_t time7 = time(NULL);

    for (int i = 0; i < min_avg_groups_qty; i++) {
        if (!strcmp(min_avg_groups[i], prev)) {
            gap++;
        } 
        else if (gap > max_gap) {
            max_gap = gap;
            max_idx = i - 1;
        }
    }

    if (gap > max_gap) {
        max_gap = gap;
        max_idx = min_avg_groups_qty - 1;
    }
    
    
    if (max_idx >= 0) {
        printf("%s\n", min_avg_groups[max_idx]);
    }
    
    time_t time8 = time(NULL);
    printf("third loop:  %ld seconds\n", time2 - time1);

    return 0;
} 