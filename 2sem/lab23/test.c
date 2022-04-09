#include <stdio.h>

void function(int *nums, int number, int size)
{
	for (int i = 0; i < size; i++)
	{
		nums[i] = number;
	}
}

int main(void)
{
	int nums[] = {1, 2, 3};
	int size = 3;
	int x = 10;

	function(nums, x, size);

	for (int i = 0; i < size; i++)
	{
		printf("%d ", nums[i]);
	}

	return 0;
}