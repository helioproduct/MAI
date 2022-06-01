#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node 
{
    int element;
    struct Node *next;
} Node;


typedef struct {
    Node *head;
    unsigned size;
} List;

// Сравнение списков
bool equal(List *lhs, List *rhs)
{
    if (lhs->size != rhs->size) {
        return false;
    }
    Node *curr1 = lhs->head->next;
    Node *curr2 = lhs->head->next;

    for (int i = 0; i < lhs->size; i++) {
        if (curr1->element != curr2->element) {
            return false;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return true;
}
