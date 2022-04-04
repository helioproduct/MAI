#include <stdio.h>

// passing copy of an int
void pass_by_val(int val)
{
	val = 10;
	printf("val = %d\n", val);
}

void pass_by_ptr(int *ptr)
{
	*ptr = 30;
}

int main(void)
{

	int a = 31;
	pass_by_ptr(&a);
	printf("%d", a);	

	return 0;
}
