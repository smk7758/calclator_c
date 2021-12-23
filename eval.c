#include "eval.h"

int eval(Node *root) {
    int val0, val1;
    if (root->left != NULL) {
        val0 = calc(root->left);
    }
    if (root->right != NULL) {
        val1 = calc(root->right);
    }
    if (root->operator != NULL) {
    return calcWithOperand(val0, val1, root->operator);
    }
    if (root->left != NULL || root->right != NULL) {
        printf("There are no expression.");
        return 0;
    }
}

int calc(Node *n) {
    if (n->operand != NULL) {
        return n->operand;
    } else if (n->operator != NULL) {
        calcWithOperand(calc(n->left), calc(n->right), n->operator);
    } else {
        printf("[Error] calc function.");
    }
}

int calcWithOperand(int left, int right, char operator) {
    switch (operator) {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            return left / right;
        default:
            printf("[Error] calcWithOperand function, cannot get operand.");
    }
}