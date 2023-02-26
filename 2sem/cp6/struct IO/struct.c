#include <stdio.h>
#include <stdlib.h>

#define STR_SIZE 80

typedef struct {
    char name[STR_SIZE];
    char surname[STR_SIZE];
    int salary;
} Employee;


void employee_write(Employee *e, FILE *f) 
{
    fwrite(&e->name, sizeof(e->name[0]), STR_SIZE, f);
    fwrite(&e->surname, sizeof(e->surname[0]), STR_SIZE, f);
    fwrite(&e->salary, sizeof(e->salary), 1, f);
}


void employee_read(Employee *e, FILE *f) 
{
    fread(&e->name, sizeof(e->name[0]), STR_SIZE, f);
    fread(&e->surname, sizeof(e->surname[0]), STR_SIZE, f);
    fread(&e->salary, sizeof(e->salary), 1, f);
}

void employee_read_txt(Employee *e, FILE *f) 
{
    fread(&e->name, sizeof(e->name[0]), STR_SIZE, f);
    fread(&e->surname, sizeof(e->surname[0]), STR_SIZE, f);
    fread(&e->salary, sizeof(e->salary), 1, f);
}

void employee_print(Employee *e, int std) 
{
    FILE *out;
    if (std) {
        out = stdout;
    }
    else {
        out = fopen("DB.txt", "aw");
    }

    fprintf(out, "%.80s ", e->name);
    fprintf(out, "%.80s ", e->surname);
    fprintf(out, "%d\n", e->salary);

    fclose(out);
}


int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: %s w to write, %s r to read\n", argv[0], argv[0]);
        exit(0);
    }

    Employee employees[] = {
        { "Vasiliy", "Petrov", 80000 },
        { "Maksim", "Trankov", 50000 },
        { "Evgeniy", "Ded", 60000 },
        { "Alla", "Ma", 65000 },
    };

    int employess_qty = sizeof(employees) / sizeof(employees[0]);

    FILE *f = NULL;

    if (argv[1][0] == 'w') {
        f = fopen("DB.bin", "w");
        
        fwrite(&employess_qty, sizeof(employess_qty), 1, f);
        for(int i = 0; i < employess_qty; ++i) {
            employee_write(employees + i, f);
        }
    }
    else if (argv[1][0] == 'r') {
        f = fopen("DB.bin", "r");

        Employee e;
        int count;

        fread(&count, sizeof(count), 1, f);
        for (int i = 0; i < employess_qty; ++i) {
            employee_read(&e, f);
            employee_print(&e, 0);
        }
    }
    else {
        printf("Usage: %s w to write, %s r to read\n", argv[0], argv[0]);
        exit(2);
    }

    fclose(f);

    return 0;
}