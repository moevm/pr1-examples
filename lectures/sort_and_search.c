#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max_int(int *arr, int n){
	int max = 0;
	for(int i=1; i<n; i++){
		if(arr[i] > arr[max])
			max = i;
	}
	return max;
}

int comparator(const void *a, const void *b){
	return *((int*)a) - *((int*)b); // (!)
}

int cmp_strs(const void *a, const void *b){
	char** str1 = (char**)a;
	char** str2 = (char**)b;
//	printf("%s, %s\n", *str1, *str2);
	return strcmp(*str1, *str2);	
}

int cmp_strs_search(const void *a, const void *b){
	char* str1 = (char*)a;
	char** str2 = (char**)b;
	printf("%s, %s\n", str1, *str2);
	return strcmp(str1, *str2);	
}

int universal_max(void *arr, int n, int size, int cmp(const void *, const void *)){
	int max = 0;
	for(int i=1; i<n; i++){
		if(cmp(arr+max*size, arr+i*size) < 0)
			max = i; 
	}
	return max;
}



int main(){
	char *strs[] = {"Hello", "Qwe", "Abc", "Mns"};
	char s[] = "Mns";
	int n = sizeof(strs)/sizeof(char*);
	qsort(strs, n, sizeof(char*), cmp_strs);
	char **res = bsearch(s, strs, n, sizeof(char*), cmp_strs_search);
	
	printf("%d\n", res - strs);
	for(int i=0; i<n; i++)
		printf("%s\n", strs[i]);
	
	return 0;
}
