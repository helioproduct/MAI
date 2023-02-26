#include <stdio.h>
#include "num.c"
#include <math.h>

// №27 После каждых двух цифр вставить абсолютное значение их разности
struct Number solution(struct Number number)
{
	struct Number result;
	
	result.size = number.size * 2 - 1;
	result.digits[0] = getDigit(number, 0);

	int j = 0;

	for (int i = 1; i < result.size; i++)
	{
		if (i % 2 == 0)
		{
			unsigned char first_digit = getDigit(number, j);
			unsigned char second_digit = getDigit(number, j - 1);
			result.digits[i] = abs(second_digit - first_digit);
		}
		else
		{
			++j;
			unsigned char digit = getDigit(number, j);
			result.digits[i] = digit;

		}
	}
	
	return result;
}

int main()
{
	int x;
	
	scanf("%d", &x);
	struct Number number = makeNumberFromInt(x);
	struct Number result = solution(number);

	printNumber(result);
	
	return 0;
}