#ifndef PARSER
#define PARSER

#include "lexer.h"
#include "stack.h"

typedef enum {
    ADD = 0,
    MULT = 1,
    POW = 2,
    INCORRECT_OPERATOR = -100
} Priority;

int operator_is_left_associative(Operator operator);
Priority priority(Operator operator);
void infix_to_postfix(Token *token, Stack *postfix_stack , Stack *operators_and_braskets_stack);


#endif // PARSER