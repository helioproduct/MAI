#include <stdio.h>
#include <stdlib.h>

#include "lexer.c"
#include "tree.c"

int calculte_operations(Tree tree)
{
    int result = 0;
    if (tree == NULL) {
        return result;
    }
    result += token_is_operator(&tree->node);
    result += calculte_operations(tree->left);
    result += calculte_operations(tree->right);

    return result;
}


int main(void)
{
    Token tokens[256];
    size_t tokens_qty = 0;

    Token token;
    token_next(&token);

    while (token.type != FINAL) {
        tokens[tokens_qty++] = token;
        token_next(&token);
    }

    Tree tree = tree_create(tokens, 0, tokens_qty - 1);

    printf("\nExpression tree:\n");
    tree_print(tree, 0);

    int result = calculte_operations(tree);
    printf("\n%d\n", result);

    return 0;
}

