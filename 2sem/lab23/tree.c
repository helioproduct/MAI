#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
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

Node* min_value_node(Node *node)
{
	Node *current = node;
	while (current != NULL && current->left != NULL)
		current = current->left;
	return current;
}

bool remove_node(Node *root, Node *prev, int value)
{
	if (root == NULL) {
		return false;
	}

	else if (value == root->value) {
		if (root->left == NULL && root->right == NULL)  {
			if (value < prev->value) {
				prev->left = NULL;
			}
			else {
				prev->right = NULL;
			}
			return true;
		}

		else if (root->left == NULL || root->right == NULL) {
			Node *child = root->left != NULL ? root->left : root->right;
			if (value < prev->value) {
				prev->left = child;
			}
			else {
				prev->right = child;
			}
			return true;
		}

		Node *min_node = min_value_node(root->right);
		int temp = min_node->value;
		remove_node(root, NULL, temp);
		root->value = temp;
		return true;
	}

	else if (value < root->value) {
		return remove_node(root->left, root, value);
	}
	
	return remove_node(root->right, root, value);
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

int height(Node *root)
{
	if (root == NULL) {
		return 0;
	}

	int left = height(root->left) + 1;
	int right = height(root->right) + 1;

	return left > right ? left : right;
}

void dfs(Node *node, int level, int *nodes_on_level)
{
	nodes_on_level[level]++;

	if (node->left != NULL) {
		dfs(node->left, level + 1, nodes_on_level);
	}

	if (node->right != NULL) {
		dfs(node->right, level + 1, nodes_on_level);
	}
}

int width(Node *root)
{
	int h = height(root);
	int nodes_on_level[h];
	memset(nodes_on_level, 0, sizeof(int) * h);

	dfs(root, 0, nodes_on_level);
	
	int mx = 0;
	for (int i = 0; i < h; i++)
	{
		if (nodes_on_level[i] > mx)
			mx = nodes_on_level[i];
	}
	return mx;	
}



int main(void)
{
	Node *root = create_node(12);
	
	insert_node(&root, 4);
	insert_node(&root, 5);
	insert_node(&root, 6);
	insert_node(&root, 7);
	insert_node(&root, 40);
	insert_node(&root, 37);
	insert_node(&root, 41);

	print_tree(root);

	printf("%d\n", width(root));

	return 0;
}
