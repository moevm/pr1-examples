#include <stdio.h>
#include <stdlib.h>

void f(int **buf){
	*buf = malloc(sizeof(int)*10);
	(*buf)[0] = 1234;
}

int main(){
	
	int **arr;
	arr = malloc(3 * sizeof(int*));
	for(int i=0; i<3; i++)
		arr[i] = malloc(sizeof(int)*3);

	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			arr[i][j] = i*10+j;

	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++)
			printf("%d ", (arr[i])[j]);
		printf("\n");
	}
//	free(arr);
	for(int i=0; i<3; i++)
		free(arr[i]);

	free(arr);
	return 0;
}
