#include <stdio.h>
#include <stdbool.h>

#include "tree.c"
#include "lexer.c"
#include "stack.c"
#include "parser.c"

int main(void)
{
    bool can_be_unary = true;
    Token token;

    Stack postfix_stack;
    Stack operators_and_brackets_stack;

    stack_create(&postfix_stack);
    stack_create(&operators_and_brackets_stack);

    while (token_read(&token, &can_be_unary)) {
        infix_to_postfix(&token, &postfix_stack, &operators_and_brackets_stack);
    }

    printf("%d", )

    return 0;
}