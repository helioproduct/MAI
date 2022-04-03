#ifndef NODE
#define NODE

typedef struct Node {
	int value;
	struct Node *left;
	struct Node *right;
} Node;


Node *create_node(int value);
void print_tree(Node *root);

#endif // NODE