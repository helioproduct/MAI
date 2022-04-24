#include <stdlib.h>

#include "stack.h"

void stack_create(Stack *stack)
{
    stack->size = 0;
    stack->top = NULL;
}

int stack_is_empty(Stack *stack)
{
    return stack->top == NULL;
}

int stack_push(Stack *stack, StackItemType *value)
{
    StackItem *item = (StackItem *)malloc(sizeof(StackItem));

    if (item == NULL) return MEMORY_NOT_ALLOCATED;

    item->data = *value;
    item->prev = stack->top;
    stack->top = item;
    stack->size++;

    return SUCCESS;
}

int stack_pop(Stack *stack)
{
    StackItem *item = NULL;

    if (stack->size == 0) return STACK_IS_EMPTY;

    item = stack->top;
    stack->top = stack->top->prev;
    stack->size--;

    free(item);

    return SUCCESS;
}

StackItemType *stack_top(Stack *stack)
{
    return &(stack->top->data);
}

void stack_destroy(Stack *stack)
{
    StackItem *item = NULL;

    while (stack->top != NULL) {
        item = stack->top;
        stack->top = stack->top->prev;

        free(item);
    }

    stack->size = 0;
    stack->top = NULL;
}