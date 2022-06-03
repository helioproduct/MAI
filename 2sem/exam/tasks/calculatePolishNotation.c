#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int N = 20;

typedef struct StackItem {
    struct StackItem *next;
    struct StackItem *prev;
    char data;
} StackItem;

typedef struct Stack {
    int size;
    StackItem *head;
} Stack;


void stack_create(Stack *s)
{
    s->head = NULL;
    s->size = 0;
}

void stack_push(Stack *s, char value)
{
    StackItem *temp;
    temp = (StackItem*)malloc(sizeof(StackItem));

    temp->data = value;

    if (s->size == 0) {
        temp->prev = NULL;
        s->head = temp;
    }
    else {
        temp->prev = s->head;
        s->head->next = temp;
        s->head = temp;
    }
    s->size++;
}

char stack_pop(Stack *s)
{
    char value;
    StackItem *temp;
    
    value = s->head->data;
    temp = s->head->prev;
    free(s->head);
    
    s->head = temp;
    s->size--;

    return value;
}


void stack_destroy(Stack *s)
{
    while (s->size > 1) {
        stack_pop(s);
    }
    
    free(s->head);
    s->head = NULL;
    s->size = 0;
}

bool isEmpty(Stack *s)
{
    return s->size;
}


int main(void)
{
    char s[N];
    scanf("%s", s);
    int i = 0;

    while (s[i] != '\0')
    {
        // заносим в стек
        // считаем
    }

    // stack_pop
}