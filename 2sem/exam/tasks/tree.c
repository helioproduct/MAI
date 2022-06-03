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


