#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
	int value;
	struct Node *left;
	struct Node *right;
} Node;


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


// Удалить листья из бинарного дерева
// Вариант 15
bool remove_leafs(Node *root, Node *prev)
{
    if (root == NULL) {
        return false;
    }
    
    if (root->left == NULL && root->right == NULL)  {
		if (prev->left == root) {
			prev->left = NULL;
		}
		else if (prev->right == root) {
			prev->right = NULL;
		}
        return true;
	}

    remove_leafs(root->left, root);
    remove_leafs(root->right, root);
}





int main(void)
{
	Node *root = create_node(12);
	
	insert_node(&root, 4);
	insert_node(&root, 3);
	insert_node(&root, 2);
	insert_node(&root, 5);
	insert_node(&root, 6);

	// print_tree(root);
    printf("\n");

    remove_leafs(root, NULL);    
    print_tree(root);

	return 0;
}
