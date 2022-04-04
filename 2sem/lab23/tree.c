#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
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

bool insert_node(Node **rootptr, int value)
{
	Node *root = *rootptr;

	if (root == NULL) {
		(*rootptr) = create_node(value); 
		return true;
	}
	else if (value == root->value) {
		return false;
	}
	else if (value < root->value) {
		return insert_node(&(root->left), value);
	}
	return insert_node(&(root->right), value);
}

bool find_node(Node *root, int value)
{
	if (root == NULL) {
		return false;
	}
	else if (value == root->value) {
		return true;
	}
	else if (value < root->value) {
		return find_node(root->left, value);
	}
	return find_node(root->right, value);
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
	Node *root = NULL;
	Node *root2 = NULL;

	/*
	insert_node(&root, 15);
	insert_node(&root, 11);
	insert_node(&root, 24);
	insert_node(&root, 5);
	insert_node(&root, 19);
	insert_node(&root, 16);


	*/

	return 0;
}