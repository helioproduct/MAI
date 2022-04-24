#ifndef STACK
#define STACK

#define MEMORY_NOT_ALLOCATED 0
#define SUCCESS 1
#define STACK_IS_EMPTY 0

#include "lexer.h"

typedef Token StackItemType;

typedef struct stack_item {
    StackItemType data;
    struct stack_item *prev;
} StackItem;

typedef struct {
    int size;
    StackItem *top;
} Stack;

void stack_create(Stack *stack);
int stack_is_empty(Stack *stack);
int stack_push(Stack *stack, StackItemType *value);
int stack_pop(Stack *stack);
StackItemType *stack_top(Stack *stack);
void stack_destroy(Stack *stack);

#endif // STACK