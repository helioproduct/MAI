#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int max(int lhs, int rhs)
{
    return lhs > rhs ? lhs : rhs;
}

typedef struct Tree {
    int value;
    struct Tree *son;
    struct Tree *brother;
} Tree;


typedef struct BinaryTree {
    int value;
    struct BinaryTree *left;
    struct BinaryTree *right;
} BinaryTree;


// Вариант 4
void depth(Tree *root, int *h, int count)
{
    if (root != NULL) {
        if (count > *h) {
            *h = count;
        }
        depth(root->son, h, count + 1);
        depth(root->brother, h, count);
    }
}


/*
    Вариант 1. Степень дерева.

    Степенью вершины - количество дуг, которое из нее выходит
    Степенью дерева - максимальное количество дуг, 
    которое из вершины этого дерева
*/
int tree_power(Tree *root)
{
    if (root == NULL) {
        return 0;
    }
    if (root->son != NULL) {
        Tree *son = root->son;
        int brothers = 0;
        while (son->brother != NULL) {
            brothers++;
            son = son->brother;
        }
        return max(brothers + 1, tree_power(son->son));
    }
}

// Степень двоичного дерева
int binary_tree_power(BinaryTree *root)
{
    int power = 0;
    if (root != NULL)
        power++;
    BinaryTree *next;

    if (root->left != NULL) {
        power++;
        next = root->left;
    }
    if (root->right != NULL) {
        power++;
        next = root->right;
    }

    if (power == 2) {
        return power;
    }
    return max(1, binary_tree_power(next));
}



bool remove_leaf(Tree *root, Tree *prev, int x)
{
	if (root == NULL) {
        return false;
	}
    if (root->son == NULL) {
        free(root);
    }   
    
}
