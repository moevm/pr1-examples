#include <stdio.h>

typedef int type;
#define ST_SIZE 20

typedef struct ArrayStack{
	type arr[ST_SIZE];
	int sp;	
} ArrayStack;

ArrayStack createStack(){
	ArrayStack stack = {{0},-1};
	return stack;
}

void push(ArrayStack *stack, type val){
	stack->arr[++(stack->sp)] = val;
}

type pop(ArrayStack *stack){
	return stack->arr[(stack->sp)--];
}

type top(ArrayStack *stack){
	return stack->arr[(stack->sp)];
}

int isEmpty(ArrayStack *stack){
	return stack->sp == -1;
}

int main(){
	ArrayStack stack = createStack();
	printf("%d\n", isEmpty(&stack));
	for(int i=0; i<10;i++)
		push(&stack, i);
	while(!isEmpty(&stack)){
		printf("%d\n", pop(&stack));
	}

	return 0;
}
