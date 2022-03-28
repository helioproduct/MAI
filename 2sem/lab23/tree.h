#ifndef _TREE_H_
#define _TREE_H_


#include "node.h"

typedef struct Tree {
	Node root;
} Tree;

Tree *create_tree(Node root_value);
Tree *tree_add_node(Tree *tree);
void print_tree(Tree *tree);


#endif // _TREE_H_