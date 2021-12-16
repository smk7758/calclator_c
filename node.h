#pragma once

#define NULL ((void *)0)

enum NodeKind {
    Operation,
    Operand
};

typedef struct __node {
    enum NodeKind kind;

    int operand;
    char operator;

    struct __node *left;
    struct __node *right;
} Node;

Node *node_new();

Node *node_new_operand(int operand);

Node *node_new_operator(char operator);

Node *node_free();

