#ifndef LEXER
#define LEXER

#include <stdbool.h>

typedef enum {
	INTEGER_VALUE,
	DOUBLE_VALUE,
	VARIABLE,
    BINARY_OPERATOR,
    UNARY_OPERATOR,
    BRACKET
} TokenType;

typedef enum { LEFT_BRACKET, RIGHT_BRACKET } Bracket;
typedef char Operator;
typedef char Variable;

typedef struct {
    TokenType type;
    union {
        int int_value;
        double double_value;
        Operator operator;
        Bracket bracket;
        Variable variable;
    } data;
} Token;

int is_operator(char c);
int is_variable(char c);
int is_bracket(char c);
int is_number(char c);
int is_space(char c);
int is_end_of_expression(char c);

int token_is_unary_operator(Token *token);
int token_is_binary_operator(Token *token);
int token_is_operator(Token *token);
int token_is_operand(Token *token);
int token_is_plus(Token *token);
int token_is_minus(Token *token);
int token_is_power(Token *token);
int token_is_variable(Token *token);
int token_is_bracket(Token *token);
int token_is_integer_value(Token *token);
int token_is_double_value(Token *token);
int token_is_positive_integer_value(Token *token);

int token_read(Token *token, bool *can_be_unary);
void token_print(Token *token);

#endif // LEXER