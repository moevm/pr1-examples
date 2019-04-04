// Optimization summation

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int recSum(int *a, int n)
{
	if(n==0)
		return 0;
	return *(a+n-1)	+ recSum(a,n-1);
}

int iterSum(int *a, int n)
{
	int sum = 0;
	int i;
	for(i=0;i<n;i++)
		sum+=*(a+i);
	return sum;	
}

int main()
{	
	int n = 100000;
	int arr[n];
	time_t time;
	time = clock();
	int res = recSum(arr,n);
	time = clock() - time;
	printf("%d %ld\n", res, time);
	
	time = clock();
	res = iterSum(arr,n);
	time = clock() - time;		
	printf("%d %ld\n", res, time);
	return 0;
}
