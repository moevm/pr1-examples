#include <stdio.h>
#include "storage.h"
#include "debug.h"

#define N 100

void printMenu(){
	char s[100] = 	"\n0 - Exit\n"
					"1 - print storage\n"
					"2 - add number\n"
					"3 - clear";
	//debugStrPrint(s);
	printf("%s\n", s);
}

int main(){
	printf(STR);
	int arr[N];
	int n = 0;
	//addToArr(arr, &n, 10); //&arr[0]
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
				printArr(arr,n);
				break;	
			case 2:
				printf("> Enter number: ");
				int numb;
				scanf("%d", &numb);
				addToArr(arr, &n, numb);
				break;	
			default:
				printf("Try again\n");
		}	
	}
	return 0;
}
