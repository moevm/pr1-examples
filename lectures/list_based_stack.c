#include <stdio.h>
#include <stdlib.h>

typedef int type;

struct Node{
  type data;
  struct Node *next;
};

struct Stack{
  struct Node *head;
  int size;
};

struct Stack stackInit(){
  struct Stack stack={NULL, 0};
  return stack;
}

void push(struct Stack *stack, type elem){
  struct Node *node = malloc(sizeof(struct Node));
  node->data = elem;
  node->next = stack->head;
  stack->head = node;
  stack->size++;
}

type pop(struct Stack *stack){
  struct Node *node = stack->head;
  stack->head = stack->head->next;
  type res = node->data;
  free(node);
  stack->size--;
  return res;
}

int isEmpty(struct Stack *stack){
  return !stack->size;
}

int main(){

  struct Stack stack = stackInit();
 
  push(&stack,10);
  push(&stack,20);
  push(&stack,30);

  while(!isEmpty(&stack)){
    printf(">>%d\n",pop(&stack));
  }

  return 0;
}
