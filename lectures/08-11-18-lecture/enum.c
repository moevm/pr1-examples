#include <stdio.h>
#include <stdlib.h>

enum En{
	OK,
	WRONG_ADDRESS,
	MALLOC_ERR
};

enum En create_array(int **a, int n);

int main(){
	enum En u = 1111;
	printf("%d\n", u);
	int *a;
	int n = -10;
	u =	create_array(&a, n);	
	switch(u){
		case OK:
			printf("OK\n");
			break;
		case WRONG_ADDRESS:
			printf("WA\n");
			return 0;
		case MALLOC_ERR:
			printf("MERR\n");
			return 0;
	}
	
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}	
	return 0;
}

enum En create_array(int **a, int n){
	if(!a)
		return 1;
	*a = malloc(n*sizeof(int));
	if(!*a){
		return MALLOC_ERR;
	}
	for(int i=0; i<n; i++)
		*((*a)+i) = i;
	return 0;
}
