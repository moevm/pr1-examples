// Example of working with a tree. Recursive and iterative printing

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

union data
{
	int n;
	char c;
};

struct node
{
	int flag; //0 - node, 1 - leaf	
	union data data;
	struct node *left;
	struct node *right;
};

void foo(struct node* root)
{ //Что делает функция??
    struct node* cur = root;
    while(!isStackEmpty() || cur!=NULL)
    {
        if(!isStackEmpty())
        {
            cur = popStack();
            if(cur->flag)
                printf("%d",cur->data.n);
            else
                printf(" %c ",cur->data.c);
            if(cur->right!=NULL)
                cur = cur->right;
            else
                cur = NULL;
        }
        while(cur!=NULL)
        {
            pushStack(cur);
            cur = cur->left;
        }
    }
}

struct node* createNode(char c, struct node *left, struct node *right)
{
	struct node *cur = malloc(sizeof(struct node));
	cur->left = left;
	cur->right = right;
	cur->flag = 0;
	cur->data.c = c;
	return cur;
}

struct node* createLeaf(int n)
{
	struct node *cur = malloc(sizeof(struct node));
	cur->left = cur->right = NULL;
	cur->flag = 1;
	cur->data.n = n;
	return cur;
}

void printTreeRec(struct node* root)
{
	if(root == NULL)
		return;
	if(root->flag)
	{
		printf("%d",root->data.n);
		return;
	}
	printf("(");
	printTreeRec(root->left);
	printf(")");
	printf(" %c ",root->data.c);
	printf("(");
	printTreeRec(root->right);
	printf(")");
}

void printTreeIter(struct node* root)
{
	struct node* cur = root;
	while(!isStackEmpty() || cur!=NULL)
	{
		if(!isStackEmpty())
		{
			cur = popStack();
			if(cur->flag)
				printf("%d",cur->data.n);
			else
				printf(" %c ",cur->data.c);
			if(cur->right!=NULL) 
				cur = cur->right;
			else
				cur = NULL;
		}
		while(cur!=NULL)
		{
			pushStack(cur);
			cur = cur->left;
		}
	}		
}

int main()
{

	struct node* root;
	//root = createNode('+',createNode('-',createLeaf(10),createLeaf(7)),createLeaf(15));
	root = createNode('+',createNode('-',createLeaf(10),createLeaf(7)),createNode('+',createLeaf(3),createLeaf(33)));
	printTreeRec(root);
	printf("\n");
	printTreeIter(root);


	return 0;
}
