#pragma once

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "calclator.h"
#include "node.h"

Node *parse(char s[]);

Node *first(char s[], int *i);
Node *second(char s[], int *i);
Node* third(char s[], int *i);
Node *fourth(char s[], int *i);
Node *number(char s[], int *i);

int toInt(char s);
int isDigits(char c[]);
int isDigit(char c);

double pow_(double left, double right);