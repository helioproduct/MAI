#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node* create_node(int element)
{
	Node* l = (Node*)malloc(sizeof(Node));
	l->element = element;
	l->next = NULL;
	return l;
}

List create_list()
{
	List l;
	l.head = NULL;
	l.size = 0;
	return l;
}


void insert(List* l, int element, unsigned position)
{
	Node* new_node = create_node(element);
	bool to_head = position == 0 || l->size == 0;

	if(to_head) {
		new_node->next = l->head;
		l->head = new_node;
		l->size++;
		return;
	}
	
    if(position > l->size) {
		position = l->size;
	}

	Node* current = l->head;
	while(position > 1)
	{
		--position;
		current = current->next;
	}
	Node* afterCurrent = current->next;
	current->next = new_node;
	new_node->next = afterCurrent;
	l->size++;
}

void insert_with_order(List *list, int element)
{
    Node *head = list->head;
    unsigned position = 0;
    while (head != NULL && head->element < element) {
        head = head->next;
        position++;
    }
    insert(list, element, position);
}


bool remove_from_list(List* l, unsigned position)
{	
	if (l->size == 0) {
		return false;
	}

    if (l->size == 1) {
        l->head = NULL;
        free(l->head);
        l->size = 0;
        return true;
    }

    if (position == 0) {
        l->head = l->head->next;
        return true;
    }

	if (position > l->size) {
		return false;
	}

	Node* current = l->head;
	while(position > 1) {
		--position;
		current = current->next;
	}

	Node* node_for_remove = current->next;
	current->next = node_for_remove->next;
	free(node_for_remove);
	l->size--;
	return true;
}


void push_back(List* list, int element)
{
    insert(list, element, list->size);
}


void push_front(List *list, int element)
{
    insert(list, element, 0);
}


bool is_empty(List *list)
{
    return list->size == 0; 
}


void print(List* l)
{
	Node* current = l->head;
	while(current != NULL) {
		printf("%d ", current->element);
		current = current->next;
	}
	printf("\n");
}


void sort(List *list)
{
    Node *root = list->head;
    Node *new_root = NULL;

    while ( root != NULL )
    {
        Node *node = root;
        root = root->next;

        if (new_root == NULL || node->element < new_root->element) {
            node->next = new_root;
            new_root = node;
        }
        else {
            Node *current = new_root;
            while (current->next != NULL && !(node->element < current->next->element))
            {                   
                  current = current->next;
            }                
            node->next = current->next;
            current->next = node;
        }
    }
    list->head = new_root;
}


int main()
{
    int a[10] = { 7, 3, 2, 1, 0, 0, 0, 5, 9, 4 };
    List list = create_list();

    for (int i = 0; i < 10; i++) {
        push_back(&list, a[i]);
    }

    print(&list);
    insert_with_order(&list, -23943949);

    print(&list);
}    