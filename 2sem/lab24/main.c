#include <stdio.h>
#include "lexer.h"

#include "stack.c"

int main(void)
{
	Token first;
	Token second;
	Token third;

	Stack stack;

	stack_create(&stack);

	stack_push(&stack, (StackItemType*) &first);
	stack_push(&stack, (StackItemType*) &second);
	stack_push(&stack, (StackItemType*) &third);

	printf("%d\n", stack.size);
	printf("%d\n", stack.size);

	return 0;
}