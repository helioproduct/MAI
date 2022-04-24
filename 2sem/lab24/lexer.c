#include "lexer.h"
#include <stdio.h>

int is_operator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int is_variable(char c)
{
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

int is_brasket(char c)
{
    return c == '(' || c == ')';
}

int is_number(char c)
{
    return c >= '0' && c <= '9';
}

int is_space(char c)
{
    return c == ' ' || c == '\t';
}

int is_end_of_expression(char c)
{
    return c == '\n';
}

int token_is_unary_operator(Token *token)
{
    return token->type == UNARY_OPERATOR;
}

int token_is_binary_operator(Token *token)
{
    return token->type == BINARY_OPERATOR;
}

int token_is_operator(Token *token)
{
    return token_is_binary_operator(token) || token_is_unary_operator(token);
}

int token_is_plus(Token *token)
{
    return token_is_operator(token) && (token->data.operator == '+');
}

int token_is_minus(Token *token)
{
    return token_is_operator(token) && (token->data.operator == '-');
}

int token_is_power(Token *token)
{
    return token_is_operator(token) && (token->data.operator == '^');
}

int token_is_variable(Token *token)
{
    return token->type == VARIABLE;
}

int token_is_brasket(Token *token)
{
    return token->type == BRACKET;
}

int token_is_integer_value(Token *token)
{
    return token->type == INTEGER_VALUE;
}

int token_is_double_value(Token *token)
{
    return token->type == DOUBLE_VALUE;
}

int token_is_positive_integer_value(Token *token)
{
    return token_is_integer_value(token) && token->data.int_value >= 0;

}

int token_read(Token *token, bool *can_be_unary)
{
    char c;
    c = fgetc(stdin);

    if (!is_end_of_expression(c)) {

        while (is_space(c)) {
            c = fgetc(stdin);
        }

        if (is_variable(c)) {
            token->type = VARIABLE;
            token->data.variable = c;
        }

        else if (is_number(c)) {
            ungetc(c, stdin);
            double value;
            scanf("%lf", &value);

            if (value == (int)value) {
                token->type = INTEGER_VALUE;
                token->data.int_value = (int)value;
            } else {
                token->type = DOUBLE_VALUE;
                token->data.double_value = value;
            }
            *can_be_unary = false;
        }

        else if (is_brasket(c)) {
            token->type = BRACKET;
            if (c == '(') {
                token->data.bracket = LEFT_BRACKET;
                *can_be_unary = true;
            } else  {
                token->data.bracket = RIGHT_BRACKET;
                *can_be_unary = false;
            }
        }

        else if (is_operator(c)) {
            if (*can_be_unary == true) {
                token->type = UNARY_OPERATOR;

            } else {
                token->type = BINARY_OPERATOR;
            }
            token->data.operator = c;
            *can_be_unary = false;
        }
    }

    return !is_end_of_expression(c);
}


void token_print(Token *token)
{
    if (token_is_integer_value(token)) {
        printf("%d", token->data.int_value);
    }
    else if (token_is_double_value(token)) {
        printf("%.4lf", token->data.double_value);
    }
    else if (token_is_variable(token)) {
        printf("%c", token->data.variable);
    }
    else if (token_is_binary_operator(token) || token_is_unary_operator(token)) {
        printf("%c", token->data.operator);
    }
    else if (token_is_brasket(token)) {
        if (token->data.bracket == LEFT_BRACKET) {
        	printf("(");
        }
        else {
            printf(")");
        }
    }
}