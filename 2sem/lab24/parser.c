#include <stdlib.h>
#include "parser.h"


Priority priority(Operator operator)
{
    if (operator == '+' || operator == '-') {
        return ADD;
    }
    if (operator == '*' || operator == '/') {
        return MULT;
    }
    if (operator == '^') {
        return POW;
    }
    return INCORRECT_OPERATOR;
}


int operator_is_left_associative(Operator operator)
{
    return operator == '+' || operator == '*' || operator == '-';
}


void infix_to_postfix(Token *token, Stack *postfix_stack , Stack *operators_and_brackets_stack)
{
    if (token_is_operand(token)) {
        stack_push(postfix_stack, token);
    }
       
    else if (token_is_operator(token)) {
        if (!stack_is_empty(operators_and_brackets_stack)) {

            Token *top_token = (Token*) malloc(sizeof(Token));
            top_token = stack_top(operators_and_brackets_stack);
            
            int condition = token_is_operator(top_token) &&
                            !stack_is_empty(operators_and_brackets_stack) &&
                            ((operator_is_left_associative(token->data.operator) &&
                            priority(token->data.operator) <= priority(top_token->data.operator)) ||
                            !operator_is_left_associative(token->data.operator) &&
                            priority(token->data.operator) < priority(top_token->data.operator));

            while (condition) {
                stack_push(postfix_stack, top_token);
                stack_pop(operators_and_brackets_stack);
                
                if (!stack_is_empty(operators_and_brackets_stack)) {
                    top_token = stack_top(operators_and_brackets_stack);
                }
            }
        }
        stack_push(operators_and_brackets_stack, token);
    }
    
    else if (token_is_left_bracket(token)) {
        stack_push(operators_and_brackets_stack, token);
    }

    else if (token_is_right_bracket(token)) {
        while (!stack_is_empty(operators_and_brackets_stack) &&
                !token_is_bracket(stack_top(operators_and_brackets_stack))) {
            stack_push(postfix_stack, stack_top(operators_and_brackets_stack));
            stack_pop(operators_and_brackets_stack);
        }
        stack_pop(operators_and_brackets_stack);
    }
}