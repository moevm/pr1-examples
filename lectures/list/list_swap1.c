#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct Node{
	int a;
	struct Node *next;
} Node;

typedef struct List{
	Node *head;
} List;

List createList(int n){
	List list = {NULL};
	for(int i=0; i<n; i++){
		Node *cur = malloc(sizeof(Node));
		cur->a = rand()%100+1;
		cur->next = list.head;
		list.head = cur;
	}
	return list;
}

void printList(List list){
	Node *tmp = list.head;
	while(tmp){
		printf("%d ", tmp->a);
		tmp = tmp->next;
	}
	printf("\n");
}

int cmp(Node *a, Node *b){
	if(b == NULL){
		return -1;
	}
	if(a->a > b->a)
		return 1;
	if(a->a < b->a)
		return -1;
	return 0;
}

void swap(Node *a, Node *b, Node *prev_a, List *list){
	a->next = b->next;
	b->next = a;
	if(prev_a) //comon
		prev_a->next = b;	
	else//head
		list->head = b;
		
}

void sortList(List *list){
	if(!list->head)
		return;
	while(1){
		int swapCount = 0;
		Node *tmp = list->head;
		Node *prev = NULL;
		while(tmp){
			if(cmp(tmp, tmp->next)>0){ //swap
				swapCount++;
				Node *next = tmp->next;
				swap(tmp, tmp->next, prev, list);
				prev = next;			
			} else {
				prev = tmp;
				tmp=tmp->next;
			}
		}
		if(!swapCount)
			return;
	}
}

int main(){
	srand(time(NULL));
	List list = createList(5);
	printList(list);
	list.head->a = 1000;
	sortList(&list);
	printList(list);
	
	return 0;
}
