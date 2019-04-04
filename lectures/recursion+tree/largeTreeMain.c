// Counting memory and time while searching in a large tree

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arrayStack.h"

int baseESP;
int maxESPOffset = 0;

int getESP()
{
	unsigned int esp;
	__asm__ (	"movl %%esp, %0\n"
				:"=r"(esp) /* выходные операнды */
				: /* входные операнды */
				: /* разрушаемые регистры */
	);
	return esp;
}

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node* createNode(int a, struct node *left, struct node *right)
{
	struct node *cur = malloc(sizeof(struct node));
	cur->left = left;
	cur->right = right;
	cur->data = a;
	return cur;
}

struct node* createLeaf(int a)
{
	return createNode(a,NULL,NULL);
}

struct node* generateTree(int depth)
{
	if(depth==0)
		return createLeaf(rand()%10);
	return createNode((rand()%10),NULL,generateTree(depth-1));
		
	
}

void printTreeRec(struct node* root)
{
	if(root == NULL)
		return;
	if(root->left!=NULL)
	{
		printf("(");
		printTreeRec(root->left);
		printf(")");
	}
	printf("%d",root->data);
	if(root->right!=NULL)	
	{
		printf("(");
		printTreeRec(root->right);
		printf(")");
	}
}

int recSum(struct node* root)
{
	
	int curEsp = getESP();
	if(baseESP - curEsp > maxESPOffset)
		maxESPOffset = baseESP - curEsp;
	
	if(root == NULL)
		return 0;
	return root->data + recSum(root->left) + recSum(root->right);
}

int iterSum(struct node* root)
{
	maxESPOffset = baseESP - getESP();// + call from this func (push, pop, etc.)
	int sum = 0;
	struct node* cur = root;
	pushStack(cur);
	while(!isStackEmpty())
	{
		cur = popStack();
		sum+=cur->data;
		if(cur->left!=NULL)
			pushStack(cur->left);
		if(cur->right!=NULL)
			pushStack(cur->right);
	}
	return sum;
}

int main()
{

	struct node* root;
	clock_t time;
	root = generateTree(25000);
	printf("generated\n");
	//printTreeRec(root);
	printf("\n");
	
	baseESP = getESP();
	maxESPOffset = 0;
	time = clock();
		recSum(root);
		//printf("%d\n",recSum(root));
	time = clock() - time;
	printf("time: %ld Max esp offset: %d\n", time, maxESPOffset);
	
	maxESPOffset = 0;
	time = clock();
		iterSum(root);
		//printf("%d\n",iterSum(root));
	time = clock() - time;
	printf("time: %ld Max esp offset: %d\n", time, maxESPOffset);



	return 0;
}
