#include "storage.h"

void addToArr(int *arr, int *n, int elem){
	arr[*n] = elem;
	(*n)++;
	printf(STR);
}

void printArr(int *arr, int n){
	printf("[");
	for(int i=0; i<n; i++){
		printf(i<n-1 ? "%d, " : "%d", arr[i]);
	}
	printf("]\n");
}
