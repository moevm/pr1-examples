#include <stdio.h>
#include <stdlib.h>

#define N 10

int* initIntArray(int n){
//	int *arr = (int*)malloc(sizeof(int)*n);
	int *arr = calloc(n, sizeof(int));
	for(int i=0; i<n; i++){
		arr[i] = i;
	}
	return arr;
}

int main(){
	int cap = 5;
	char *s = malloc(cap);
	char c;
	int i = 0;
	while((c = getchar()) != '\n'){
		printf("processing %c on %d iteration\n", c, i);
		if(i == (cap-1)){
			printf("realloc %d -> %d\n", cap, cap+5);
			char *t = realloc(s, cap+5);
			if(t){
				s = t;
				cap += 5;
			}else {
				// error handler
			}
		}
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	puts(s);


	int *p = initIntArray(30);
	int *temp = realloc(p, sizeof(int)*60);
	if(temp){ // temp != NULL
		p = temp;
	} else {
		// ???
	}

	free(p);


	return 0;
}
