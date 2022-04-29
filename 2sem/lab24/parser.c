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
    
    /*
    if (token_is_integer_value(token) ||
            token_is_double_value(token) ||
            (token_is_variable(token))) {
        stack_push(postfix_stack, token);
    } */
    
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
    
    else if (token_is_bracket(token)) {
        if (token->data.bracket == LEFT_BRACKET) {
            stack_push(operators_and_brackets_stack, token);
        } else    {
            while (!stack_is_empty(operators_and_brackets_stack) &&
                    !token_is_bracket(stack_top(operators_and_brackets_stack))) {
                stack_push(postfix_stack, stack_top(operators_and_brackets_stack));
                stack_pop(operators_and_brackets_stack);
            }
            stack_pop(operators_and_brackets_stack);
        }
    }
}




void algo(Token *token, Stack *postfix_stack, Stack *operators_and_brackets) {
    if (token_is_operand(token)) {
        stack_push(postfix_stack, token);
    }
    
    else if (token_is_left_bracket(token)) {
        stack_push(operators_and_brackets, token);
    }

    else if (token_is_right_bracket(token)) {
        
        Token *top_token = (Token*) malloc(sizeof(Token));
        top_token = stack_top(operators_and_brackets);

        while (!token_is_left_bracket(top_token)) {
            stack_push(postfix_stack, top_token);
            stack_pop(operators_and_brackets);
            top_token = stack_top(operators_and_brackets);

            if (token_is_left_bracket(top_token)) {
                stack_pop(operators_and_brackets);
            }
        }

    }

    else if (token_is_binary_operator(token)) {
        if (!stack_is_empty(operators_and_brackets)) {
            Token *top_token = (Token*) malloc(sizeof(Token));
            top_token = stack_top(operators_and_brackets);

            int condition = token_is_operator(token) && 
                            priority(token->data.operator) >= priority(top_token->data.operator) ||
                            operator_is_left_associative(top_token->data.operator) &&
                            priority(token->data.operator) == priority(token->data.operator);

            while (condition) {
                stack_push(postfix_stack, stack_top(operators_and_brackets));
                stack_pop(operators_and_brackets);
            }
        }

        stack_push(operators_and_brackets, token);
    }

}

/*
void infix_to_postfix(Token *token, Stack *postfix_stack , Stack *operators_and_brackets_stack)
{
    if (token_is_integer_value(token) || token_is_double_value(token) || token_is_variable(token)) {
        stack_push(postfix_stack, token);
    }
    
    else if (token_is_operator(token)) {
        if (!stack_is_empty(operators_and_brackets_stack)) {
            Token *top_token = (Token *) malloc(sizeof(Token));            
            top_token = stack_top(operators_and_brackets_stack);
            
            int condition = token_is_operator(top_token) && 
                            (priority(top_token->data.operator) >= priority(token->data.operator) ||

                            operator_is_left_associative(top_token->data.operator) &&
                            priority(top_token->data.operator) == priority(token->data.operator));

            while (condition) {
                stack_push(postfix_stack, top_token);
                stack_pop(operators_and_brackets_stack);
            }
        }
        
        stack_push(operators_and_brackets_stack, token);
    }  

    else if (token_is_left_bracket(token)) {
        stack_push(postfix_stack, token);
    }

    else if (token_is_right_bracket(token)) {

        while (!token_is_left_bracket(stack_top(operators_and_brackets_stack))) {
            stack_push(postfix_stack, stack_top(operators_and_brackets_stack));
            stack_pop(operators_and_brackets_stack);
        }   

    }
}
*/