#ifndef TREE
#define TREE

#include "lexer.h"
#include "stack.h"

typedef struct Node {
	Token token;
	struct Node *left;
	struct Node *right;
} Node;

Node *tree_node_create(Token *token);
void tree_build(Node **node, Stack *postfix_stack);
void tree_print_subtree(Node *node, int depth);
void tree_print(Node *node);
void tree_delete(Node **node);
void tree_infix_linearization(Node *node);

#endif // TREE