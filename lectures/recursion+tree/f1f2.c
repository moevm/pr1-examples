#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//sizeof parameters
//other calls

struct S{
	double s[100];
};

struct S1{
	char c[100];
};

void f(struct S s, int i){
	//printf("%d ",i);
	if(i>0)
		f(s,--i);
}

void f1(struct S1 c, int i){
//	printf("%d ",i);
	if(i>0)
		f1(c,--i);
}

int main()
{
	
	struct S s;
	struct S1 s1;
	printf("%lu, %lu\n", sizeof(char), sizeof(double));
	f (s, 10000);
	//f1(s1,60000);
	printf("sizeof(S1) = %lu\n", sizeof(struct S1));
	printf("sizeof(S1) = %lu\n", sizeof(struct S));
//	f1(s1,58000);
		
	return 0;
}
