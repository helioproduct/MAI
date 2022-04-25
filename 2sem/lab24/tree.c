#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

Node *tree_node_create(Token *token)
{
    Node *node = (Node *)malloc(sizeof(Node));

    node->token = *token;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void tree_build(Node **node, Stack *postfix_stack)
{
    Token token;

    if (!stack_is_empty(postfix_stack)) {
        token = *stack_top(postfix_stack);
        stack_pop(postfix_stack);

        (*node) = tree_node_create(&token);

        if (token_is_operator(&token)) {
            tree_build(&(*node)->right, postfix_stack);

            if (token_is_binary_operator(&token)) {
                tree_build(&(*node)->left, postfix_stack);
            }
        }
    }
}

void tree_print_subtree(Node *node, int depth)
{
    if (node != NULL) {
        for (int i = 0; i < depth; ++i) {
            printf("__");
        }

        token_print(&(node->token)); printf("\n");

        tree_print_subtree(node->left,  depth + 1);
        tree_print_subtree(node->right, depth + 1);
    }
}

void tree_infix_linearization(Node *node) // не нужно же заморачитаться с выводом без лишних скобок?
{
    if (node != NULL) {
        if ((node->left != NULL) && (node->right) != NULL)
            printf("(");

        tree_infix_linearization(node->left);
        token_print(&(node->token));
        tree_infix_linearization(node->right);

        if (node->right && node->left)
            printf(")");
    }
}


void tree_print(Node *node)
{
    tree_print_subtree(node, 0);
}



void tree_delete(Node **node)
{
    if ((*node) != NULL) {
        tree_delete(&((*node)->left));
        tree_delete(&((*node)->right));
    }
    free(*node);
    *node = NULL;
}