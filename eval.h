#pragma once

#include <stdio.h>
#include <string.h>
#include "calclator.h"
#include "node.h"

int eval(Node *node);
int calc(Node *n);
int calcWithOperand(int left, int right, char operand);