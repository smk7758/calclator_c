
int calc(Node *n);
int calcWithOperand(int left, int right, char operand);


int eval(Node *node);

Node *parse(char s[]);

Node *first(char s[], int *i);
Node *second(char s[], int *i);
Node *third(char s[], int *i);
Node *number(char s[], int *i);

int toInt(char s);
int isDigits(char c[]);
int isDigit(char c);