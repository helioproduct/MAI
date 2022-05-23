#ifndef STUDENT
#define STUDENT

#define STR_SIZE 24

typedef struct {
    char surname[STR_SIZE];     // Фамилия
    char initials[STR_SIZE];    // Инициалы
    char gender;                
    int  group;
    int  dm, ma, la, cs, hi;    // Оценки
} Student;

#endif // STUDENT