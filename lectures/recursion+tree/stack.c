#include "stack.h"

int isStackEmpty()
{
	if(root == NULL)
		return 1;
	else
		return 0;
}

void pushStack(TYPE item)
{
	struct stackNode * cur = malloc(sizeof(struct stackNode));
	cur->item = item;
	cur->next = root;
	root = cur;
}

TYPE popStack()
{
	struct stackNode * cur = root;
	root = cur->next;
	TYPE ret = cur->item;
	free(cur);
	return ret;
}
