#include <stdio.h>
#include <stdbool.h>

#include "lexer.c"
#include "stack.c"

int main(void)
{
	bool can_be_unary = true;

	Token token;
	Stack stack;

	stack_create(&stack);

	while (token_read(&token, &can_be_unary))
	{
		stack_push(&stack, (StackItemType*) &token);
		token_print(&token);
		printf("\n");


		token_read(&token, &can_be_unary);
	}

	printf("%d", stack.size);

	return 0;
}