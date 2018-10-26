#include <stdio.h>

void printBin(char c){
	unsigned char mask = 1<<(sizeof(char)*8-1);
	for(;mask;mask>>=1){
		printf("%d", c&mask?1:0);
	}
	printf("\n");
}

int main(){
	signed char c = 123;
	c |= 1<<0;
	printBin(c);
	c &= ~(1<<3);
	printBin(c);
	printf("%d\n", c);
	return 0;
}
