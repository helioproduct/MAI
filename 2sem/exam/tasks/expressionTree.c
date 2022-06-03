#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	char key;
	struct Node *left;
	struct Node *right;
} Node;



void task(Node *root)
{
    if ((root->key == '*') && ((root->left == '1') || (root->right == 1))) {
        if (root->left->key == '1') {
            free(root->left);
            tmp = root->right;
            free(root);
            root = tmp;
        }
    }
    

}