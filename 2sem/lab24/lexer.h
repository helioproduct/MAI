#ifndef __LEXER_H__
#define __LEXER_H__

#include <stdbool.h>

typedef enum {
    FINAL,
    INTEGER,
    FLOATING,
    OPERATOR,
    VARIABLE,
    BRACKET
} TokenType;

typedef struct {
    TokenType type;
    union {
        int   value_int;
        float value_float;
        char  operator_name;
        bool  is_left_bracket;
        char  variable_name;
    } data;
} Token;

void token_print(Token *t);
void token_next(Token *t);

bool token_is_operator(Token *token);

#endif
