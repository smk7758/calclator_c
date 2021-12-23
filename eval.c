#include "eval.h"

#define plus(s1,s2) (s1)+(s2)
#define minus(s1,s2) (s1)-(s2)
#define multiply(s1,s2) (s1)*(s2)
#define divide(s1,s2) (s1)/(s2)

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
            return plus(left, right);
        case '-':
            return minus(left, right);
        case '*':
            return multiply(left,right);
        case '/':
            return divide(left, right);
        default:
            printf("[Error] calcWithOperand function, cannot get operand.");
    }
}