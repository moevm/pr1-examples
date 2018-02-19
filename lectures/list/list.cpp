// Programming 1. Sample at 2017-11-16-14-05.38
#include <stdio.h>
#include <stdlib.h>
typedef int dataType;

struct Person
{
  dataType data;
	struct Person *next;
};

struct Person *list=NULL;

void print_list(struct Person *list);

void del_item(struct Person **list, int n);

void add_item(struct Person **list, struct Person *item, int tail);

struct Person* createNode(dataType n){
  struct Person *node  = (struct Person*) malloc(sizeof(struct Person));
  node->data = n;
  node->next = NULL;
  return node;
}

int main(/*int c, char **v */)
{
  add_item(&list, createNode(10),0);
  add_item(&list, createNode(20),0);
  add_item(&list, createNode(30),0);
	print_list(list);
	
  return 0;
}

void print_list(struct Person *list)
{
	while(list)
	{
		printf("%d\n",list->data);
		list = list->next;
	}
}

void del_item(struct Person **list, int n)
{
	if(*list == NULL)
		return;

	if(n==0)
	{
		(*list) = (*list)->next;
		return;
	}

	struct Person *current = *list;
	while(current && (n--) > 1)
	{
		current=current->next;
	}

	if(current->next)

		current->next = current->next->next;

}

void add_item(struct Person **list, struct Person *item, int tail)
{
	if(*list == NULL) // adding 1st item
	{
	  (*list) = item;
	  return;		
	}

	if(tail == 0)
	{
		item->next = *list;
		(*list) = item;
		return;		
	}

	struct Person *current = *list;

	while(current)
	{
		if(current->next == NULL)
		{
			current->next = item;
			return;
		}
		else
		{
			current = current->next;
		}
	}
}

