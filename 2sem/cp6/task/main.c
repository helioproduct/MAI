#include <float.h>
#include <string.h>
#include "io.c"

typedef struct {
    double avg_mark;
    char group[STR_SIZE];    
} StudentStat;


int sortstring( const void *str1, const void *str2 )
{
    char *const *pp1 = str1;
    char *const *pp2 = str2;
    return strcmp(*pp1, *pp2);
}

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
    
    StudentStat students[200] = { {0.0, ""} };
    int students_qty = 0;

    char* min_avg_groups[200] = { "" };
    int min_avg_groups_qty = 0;

    Student student;

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

    for (int i = 0; i < students_qty; i++) {
        if (students[i].avg_mark == min_avg) {
            min_avg_groups[min_avg_groups_qty++] = students[i].group;
        }
    }

    qsort(min_avg_groups, min_avg_groups_qty, sizeof(min_avg_groups[0]), sortstring);

    int max_gap = 0;
    int max_idx = -1;
    int gap = 0;
    char* prev = min_avg_groups[0];

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

    return 0;
} 