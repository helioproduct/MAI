#include <stdlib.h>
#include "parser.h"


int operator_is_left_associative(Operator operator)
{
    return operator == '+' || operator == '-' || operator == '*' || operator == '/';
}


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


void infix_to_postfix(Token *token, Stack *postfix_stack , Stack *operators_and_brackets_stack)
{
    if (token_is_integer_value(token) ||
            token_is_double_value(token) ||
            (token_is_variable(token))) {
        stack_push(postfix_stack, token);
    }
    
    else if (token_is_operator(token)) {
        if (!stack_is_empty(operators_and_brackets_stack)) {
            Token *top_token = (Token *) malloc(sizeof(Token));
            top_token = stack_top(operators_and_brackets_stack);
            
            while ((token_is_operator(top_token))
                    && (!stack_is_empty(operators_and_brackets_stack)) &&
                    ((operator_is_left_associative(token->data.operator) &&
                      priority(token->data.operator) <= priority(top_token->data.operator)) ||
                     (!operator_is_left_associative(token->data.operator) &&
                      priority(token->data.operator) < priority(top_token->data.operator)))) {
                      
                stack_push(postfix_stack, top_token);
                stack_pop(operators_and_brackets_stack);
                
                if (!stack_is_empty(operators_and_brackets_stack)) {
                    top_token = stack_top(operators_and_brackets_stack);
                }
            }
        }
        
        stack_push(operators_and_brackets_stack, token);
    }
    
    else if (token_is_brasket(token)) {
        if (token->data.bracket == LEFT_BRACKET) {
            stack_push(operators_and_brackets_stack, token);
        } else    {
            while (!stack_is_empty(operators_and_brackets_stack) &&
                    !token_is_brasket(stack_top(operators_and_brackets_stack))) {
                stack_push(postfix_stack, stack_top(operators_and_brackets_stack));
                stack_pop(operators_and_brackets_stack);
            }
            stack_pop(operators_and_brackets_stack);
        }
    }
}