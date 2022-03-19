#include <stdio.h>
#include <stdlib.h>

typedef float balance;

typedef struct {
	float due;
	int over_due;
	char name[40];
} client; /* здесь client - это имя нового типа */

int main(void)
{	
	balance b = 2.0;
	printf("%f\n", b);

	client clist[10]; /* определение массива структур типа client */

	return 0;
}