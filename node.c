#include <stdlib.h>
#include "node.h"

Node *node_new() {
    Node *n = malloc(sizeof(Node));
    if (n != NULL) {
        n->left = NULL;
        n->right = NULL;
    }

    return n;
}

Node *node_new_operand(int operand) {
    Node *n = node_new();
    n->operand = operand;
    n->kind = Operand;
    return n;
}

Node *node_new_operator(char operator) {
    Node *n = node_new();
    n->operator = operator;
    n->kind = Operation;
    return n;
}

// なくてもいい
Node *node_free(Node *n) {
    free(n);
}