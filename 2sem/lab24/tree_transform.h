#ifndef TREE_TRANSFORM
#define TREE_TRANSFORM

#include "lexer.h"
#include "stack.h"
#include "tree.h"

int tree_must_be_transformed_unary(Node **node);
int tree_must_be_transformed_power(Node **node);
void transform_unary(Node **node);
void transform_power(Node **node);
void tree_transform(Node **node);

#endif // TREE_TRANSFORM