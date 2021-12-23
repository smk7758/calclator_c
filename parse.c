#include "parse.h"

Node* parse(char s[]) {
    int i = 0;
    return first(s, &i);
}

Node* first(char s[], int *i) {
    Node *left = second(s, i);
    while (s[*i] == '+' || s[*i] == '-') {
        char operand = s[*i];
        (*i)++;
        Node *node = node_new_operator(operand);
        node->left = left;
        node->right = second(s, i);
        left = node;
    }

    return left;
}

Node* second(char s[], int *i) {
    Node *left = third(s, i);
    while (s[*i] == '*' || s[*i] == '/') {
        char operand = s[*i];
        (*i)++;
        Node *node = node_new_operator(operand);
        node->left = left;
        node->right = fourth(s, i);

        left = node;
    }

    return left;
}

double pow_(double left, double right) {
    return pow(left, right);
}

Node* third(char s[], int *i) {
    Node *left = fourth(s, i);
    while (s[*i] == '^') {
        (*i)++;
        
        char operand = s[*i]; // "^"
        Node *node = node_new_operator(operand);
        node->calcOperator = pow_; // 関数ポインタ

        node->left = left;
        node->right = fourth(s, i);

        left = node;
    }

    return left;
}

Node* fourth(char s[], int *i) {
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

Node* number(char s[], int *i) {     
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