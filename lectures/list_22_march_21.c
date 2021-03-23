#include <stdio.h>
#include <stdlib.h>

typedef struct Elem{
	int data;
	struct Elem* next;
} Elem;


void printList(struct Elem *head){
	while(head){
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}


struct Elem* createElem(int data, struct Elem* next){
	struct Elem *cur = (Elem*) malloc(sizeof(struct Elem));
	cur->data = data;
	cur->next = next;
	return cur;
}

void append(struct Elem* head, int data){
	while(head->next != NULL)
		head = head->next;
	struct Elem* cur = createElem(data, NULL);
	head->next = cur;
}

void insert(struct Elem* head, int val, int new_val){
	while(head->data!=val){
		head = head ->next;
	}
	struct Elem* cur = createElem(new_val, head->next);
	head->next = cur;
}


void clear(struct Elem *head){
	while(head!=NULL){
		struct Elem *tmp = head->next;
		free(head);
		head = tmp;
	}
}

void removeElem(struct Elem *head, int val){ //count(head) >=2
	struct Elem *cur = head->next;
	struct Elem *prev = head;
	while(cur->data!=val){
		prev = cur;
		cur = cur->next;
	}

	prev->next = cur->next;
	free(cur);

}

void pushFront(Elem **head, int val){
	struct Elem* cur = createElem(val, *head);
	*head = cur;
	printList(*head);
}

void swap(Elem **head, Elem *a_prev, Elem *b_prev){
	Elem* b = b_prev->next;
	Elem* a = *head;
	Elem* tmp = b->next;
	if(a_prev == NULL){
		if(a->next == b){
			b->next = a;
		} else {
			b->next = a->next;
			b_prev->next = a;
		}
		a->next = tmp;
		*head = b;
		return;
	}
	a = a_prev->next;
	if(b_prev == a){
		a_prev->next = b;
		b->next = a;
		a->next = tmp;
		return;	
	}
	b->next = a->next;
	a->next = tmp;
	tmp = b_prev->next;
        b_prev->next = a_prev->next;
        a_prev->next = tmp;
}

void swap_usr(Elem **head, int a, int b){
	Elem *cur = *head;
	Elem *a_prev = NULL;
	Elem *b_prev = NULL;
	while(cur->next){
		if(cur->next->data == a)
			a_prev = cur;
		if(cur->next->data == b)
			b_prev = cur;
		cur = cur->next;
	}
	swap(head, a_prev, b_prev);
}

void sort(Elem **head){
	Elem *cur = *head;
	Elem *cur_prev = NULL;
	while(cur){
		if(cur->data > cur->next->data){
			swap(head, cur_prev, cur);
		}
		cur_prev = cur;
		cur = cur->next;
	}
}


int main(){
	struct Elem *head = createElem(1200, createElem(66, createElem(30, NULL)));
	append(head, -40);
	append(head, 500);
	append(head, 60);
	printList(head);

	//swap_usr(&head, 10, 60);

	printList(head);
	sort(&head);
	printList(head);

	clear(head);

	return 0;
}
