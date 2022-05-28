#ifndef LIST
#define LIST
 
#include <stdbool.h>

struct node
{
	int element;
	struct node* next;
};

typedef struct node Node;

typedef struct {
	Node* head;
	unsigned size;
} List;


List create_list();

void insert(List *list, int element, unsigned position);

void insert_with_order(List *list, int element);

bool remove_from_list(List *list, unsigned position);

void push_back(List *list, int element);

void push_front(List *list, int element);

bool is_empty(List *list);

void clear(List *list);

void print(List *list);

void sort(List *list);

#endif