#include <iostream>
using std::cout;
using std::endl;
struct Elem{
	int data;
	Elem *next;
};

struct List{
	Elem *head;
};

void printList(const List *list){
	cout<<"[ ";
	Elem *head = list->head;
	while(head){
	    cout<<head->data<<" ";
		head = head->next;
	}
	cout<<"]"<<endl;
}

void pushBack(List *list, Elem *toAdd){
	toAdd->next = NULL;
	if(!(list->head)){
		list->head = toAdd;
		return;
	}
	Elem *cur = list->head;
	while(cur->next){
		cur = cur->next;
	}
	cur->next = toAdd;
}

Elem* newElem(int data, Elem *next = NULL){
	Elem *cur = new Elem;
	cur->data = data;
	cur->next = next;
	return cur;
}

List *newList(Elem *elem = NULL){
	List *list = new List;
	list->head = elem;
	return list;
}

void rmElem(List *list, int val){
	Elem *cur, *prev;
	cur = list->head;
	prev = NULL;

	while(cur && cur->data != val){
		prev = cur;
		cur = cur->next;
	}
	if(!cur){return;}
	if(!prev){
		list->head = cur->next;
		delete cur;
		return;
	}
	prev->next = cur->next;
	delete cur;
	
}

void swap(Elem *a_prev, Elem *b_prev){
	Elem *a = a_prev->next;
	Elem *b = b_prev->next;
	Elem *b_next = b->next;
	b->next = a->next;
	if(a->next == b){
		b->next = a;
		a->next = b_next;
		a_prev->next = b;
		return;
	}
	a->next = b_next;
	a_prev->next = b;
	b_prev->next = a;
}

void sort(List *list){
	Elem *a = list->head;
	Elem *b = a->next;
	int swap_count = 0;
	do{
		swap_count = 0;
		a = list->head;
		b = a->next;
		while(b->next){
			if(a->next->data > b->next->data){
				swap(a,b);
				swap_count++;
				b = a->next;
				a = b;
			} else{
				a = b;
				b = b->next;
			}
		}
	}while(swap_count);
}

int main(){
	List *list = newList();
	Elem* arr[] = { newElem(60),
					newElem(50),
					newElem(40),
					newElem(30),
					newElem(20),
					newElem(10)};
for(int i=0; i<sizeof(arr)/sizeof(Elem*); i++)
	pushBack(list, arr[i]);

printList(list);
sort(list);
printList(list);	 
	
	return 0;
}
