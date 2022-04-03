#include <stdlib.h>
#include <stdio.h>

#include "node.h"

Node *create_node(int value)
{
	Node *result = malloc(sizeof(Node));
	if (result != NULL) {
		result->value = value;
		result->left = NULL;
		result->right = NULL;
	}
	return result;
}

void print_tabs(int level)
{
	for (int i = 0; i < level; i++)
	{
		printf("\t");
	}
}


void print_tree_rec(Node *root, int level)
{
	if (root == NULL) {
		print_tabs(level);
		printf("---<empty>---\n");
		return;
	}

	print_tabs(level);
	printf("value = %d\n", root->value);
	
	print_tabs(level);
	printf("left\n");

	print_tabs(level);
	print_tree_rec(root->left, level + 1);

	print_tabs(level);
	printf("right\n");

	print_tabs(level);
	print_tree_rec(root->right, level + 1);

	print_tabs(level);
	printf("done\n");
}

void print_tree(Node *root) 	
{
	print_tree_rec(root, 0);
}


int main(void)
{
	Node *n1 = create_node(10);
	Node *n2 = create_node(11);
	Node *n3 = create_node(12);
	Node *n4 = create_node(13);
	Node *n5 = create_node(14);

	// connecting into tree
	n1->left = n2;
	n1->right = n3;
	n3->left = n4;
	n3->right = n5;

	print_tree(n1);

	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);

	return 0;
}