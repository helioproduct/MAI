#include "num.h"
#include <math.h>

struct Number makeNumberFromInt(int number)
{
	struct Number n = {.digits = {0}, .size = 0}; 
	n.positive = number >= 0 ? true : false;

	if (number == 0)
	{
		n.size++;
		return n;
	}

	number = abs(number);
	int temp_number = number;
	
	while (temp_number > 0)
	{
		n.size++;
		temp_number /= 10;
	}
	
	for (int i = n.size - 1; i >= 0; i--)
	{
		n.digits[i] = number % 10;
		number /= 10;
	}

	return n;
}

unsigned char getDigit(struct Number n, unsigned index)
{
	return n.digits[index];
}

int makeIntFromNumber(struct Number n)
{
	int result = 0;
	
	for (int i = n.size; i >= 0; i--)
	{		
		result += pow(10, i) * n.digits[i];
	}

	return result;
}

void printNumber(struct Number n)
{
	for (int i = 0; i < n.size; i++)
	{
		if (i != n.size - 1)
		{
			printf("%d", n.digits[i]);
		}
		else
		{
			printf("%d \n", n.digits[i]);
		}
	}
}

void clear(struct Number *n)
{
	for (int i = 0; i < (*n).size; i++)
	{
		(*n).digits[i] = 0;
	}

	(*n).size = 0;
}
