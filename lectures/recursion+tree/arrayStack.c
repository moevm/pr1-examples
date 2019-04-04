#include "arrayStack.h"

int isStackEmpty()
{
	if(stackTop == -1)
		return 1;
	else
		return 0;
}

void pushStack(TYPE item)
{
	stackTop++;
	stackArr[stackTop] = item;
}

TYPE popStack()
{
	TYPE item = stackArr[stackTop];
	stackTop--;
	return item;
}
