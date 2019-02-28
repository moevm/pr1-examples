#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
} Node;

Node* createNode(int a, Node *next){
	Node *tmp = calloc(1, sizeof(Node));
	tmp->data = a;
	tmp->next = next;
	return tmp;
}

void printList(Node* head){
	printf("[ ");
	while(head){
		printf("%d ", head -> data);
		head = head->next;
	}
	printf("]\n");
}

void pushFront(Node **head, int n){
	Node *tmp = createNode(n, *head);
	*head = tmp;
}

void pushBack(Node **head, int n){
	if(!*head){
		pushFront(head, n);
		return;
	}
	while((*head)->next){
		*head = (*head)->next;
	}
	(*head)->next = createNode(n, NULL);
}

void insert(Node **head, int elem, int i){
	if(!*head || !i){
		pushFront(head, elem);
		return;
	}
	Node *cur = *head;
	Node *prev = NULL;
	while(cur && i>0){
		prev = cur;
		cur = cur->next;
		i--;
	}
	Node *tmp = createNode(elem, cur);
	prev->next = tmp;
}

int rem(Node **head, int val){
	if(!*head)
		return 0;
	if((*head)->data == val){
		Node *t = *head;
		*head = (*head)->next;
		free(t);
		return 0;
	}
	Node *cur = *head;
	Node *prev = NULL;
	while(cur && cur->data != val){
		prev = cur;
		cur = cur->next;
	}
	if(!cur)
		return -1;
	prev->next = cur->next;
	free(cur);
	return 0;

}

int main()
{
//	Node *head = createNode(1, createNode(2,NULL));
	Node *head = NULL;
	pushBack(&head,10);
	pushBack(&head,20);
	pushFront(&head, 30);
//	printList(head);
	insert(&head, 100, 70);
	insert(&head, 90, 3);
	insert(&head, 0, 0);
	insert(&head, -10, 0);
	printList(head);
	rem(&head, -10);	
	printList(head);
	rem(&head, -10);	
	printList(head);
	rem(&head, -15);	
	printList(head);
	rem(&head, 100);	
	printList(head);
	rem(&head, 20);	
	printList(head);
	
	return 0;
}

