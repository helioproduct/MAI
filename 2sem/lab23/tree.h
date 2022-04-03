#ifndef TREE
#define TREE

#include "node.h"

typedef struct Tree {
	Node root;
} Tree;

Tree *create_tree(Node root_value);
Tree *add_node(Tree *tree);
void print_tree(Tree *tree);

#endif // NODE