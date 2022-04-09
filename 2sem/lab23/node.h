#ifndef NODE
#define NODE

#include <stdbool.h>

typedef struct Node {
	int value;
	struct Node *left;
	struct Node *right;
} Node;

Node *create_node(int value);

bool insert_node(Node **rootptr, int value);

bool find_node(Node *root, int value);

void print_tree(Node *root);

bool remove_node(Node *root, Node *prev, int value);

void export_tree(Node *root);

int height(Node *root);

#endif // NODE