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
void export_tree(Node *root);

bool insert_node2(Node *root, int value);

#endif // NODE