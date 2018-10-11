#include <stdio.h>

#define N 100

void debugStrPrint(char *s){
  for(int i=0; s[i]; i++)
      printf("[%c](%d)\n", s[i], s[i]);
}

void printMenu(){
	char s[100] = 	"\n0 - Exit\n"
					"1 - print storage\n"
					"2 - add number\n"
					"3 - clear";
	//debugStrPrint(s);
	printf("%s\n", s);
}

void addToArr(int *arr, int *n, int elem){
	arr[*n] = elem;
	(*n)++;
}

int main(){
	int arr[N];
	int n = 0;
	printf("Before:\n");
	for(int i=0; i<n; i++){
		printf("%d\n", arr[i]);
	}
	addToArr(arr, &n, 10); //&arr[0]
	printf("After:\n");
	for(int i=0; i<n; i++){
		printf("%d\n", arr[i]);
	}
	return 0;
	printf("Hello, User!\n\n");
	int choice;
	while(1){ //for(;;)
		printMenu();
		scanf("%d", &choice);
		switch(choice){
			case 0:
				printf("I will miss you...\n");
				return 0;
			case 1:
				printf(">1\n");
				break;	
			case 2:
				printf(">2\n");
				break;	
			default:
				printf("Try again\n");
		}	
	}
	return 0;
}
