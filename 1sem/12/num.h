#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Number {
	unsigned char digits[100];
	bool positive;
	unsigned short size;
};

struct Number makeNumberFromInt(int n);

unsigned char getDigit(struct Number n, unsigned index);

int makeIntFromNumber(struct Number n);

void printNumber(struct Number n);

void clear(struct Number *n);
