#include <stdio.h>
#include <string.h>
#include "node.h"
#include "calclator.h"

#define NULL ((void *)0)
#define FALSE 0
#define TRUE 1

#define DEFAULT_LINE_SIZE 128

int main(void) {
    char line[DEFAULT_LINE_SIZE];
    scanf("%s", line);

    Node *root = parse(line);

    const int result = eval(root);

    printf("%s = %d \n", line, result);

    return 0;
}

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

Node *parse(char s[]) {
    int i = 0;
    return first(s, &i);
}

Node *first(char s[], int *i) {
    Node *left = second(s, i);
    while (s[*i] == '+' || s[*i] == '-') {
        char op = s[*i];
        (*i)++;
        Node *node = node_new_operator(op);
        node->left = left;
        node->right = second(s, i);
        left = node;
    }

    return left;
}

Node *second(char s[], int *i) {
    Node *left = third(s, i);
    while (s[*i] == '*' || s[*i] == '/') {
        char op = s[*i];
        (*i)++;
        Node *node = node_new_operator(op);
        node->left = left;
        node->right = third(s, i);

        left = node;
    }

    return left;
}

Node *third(char s[], int *i) {
    if (isDigit(s[*i])) return number(s, i);

    // 構文が正しければ、このときs[i] == '('
    if (s[*i] != '(') {
        printf("[error] %c != '(' \n", s[*i]);
    }
    (*i)++; // '('を飛ばす
    Node *node = first(s, i);

    if (s[*i] != ')') {
        printf("[error] %c != ')' \n", s[*i]);
    }
    (*i)++; // ')'

    return node;
}

Node *number(char s[], int *i) {     
    int num = toInt(s[*i]);
    (*i)++;
    while (isDigit(s[*i])) {
        num = num * 10 + toInt(s[*i]);
        (*i)++;
    }

    return node_new_operand(num);
}

int toInt(char s) {
    return (int)(s - '0');
}

int isDigits(char c[]) {
    int i = 0;
    const int len = strlen(c);
    for (i = 0; i < len; i++) {
        if (!isDigit(c[i])) return FALSE;
    }

    return TRUE;
}

int isDigit(char c) {
    return '0' <= c && c <= '9';
}