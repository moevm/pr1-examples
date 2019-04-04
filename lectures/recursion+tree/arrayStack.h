#include <stdio.h>
#include <stdlib.h>

#define TYPE struct node *

struct node;

static TYPE stackArr[1000];
static int stackTop = -1;

int isStackEmpty();

void pushStack(TYPE item);

TYPE popStack();
