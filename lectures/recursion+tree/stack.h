#include <stdio.h>
#include <stdlib.h>

#define TYPE struct node *

struct node;

struct stackNode
{
	TYPE item;
	struct stackNode *next;
};

static struct stackNode *root = NULL;

int isStackEmpty();

void pushStack(TYPE item);

TYPE popStack();
