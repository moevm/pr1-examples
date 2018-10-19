#include <stdio.h>
// Что тут происходит? 1)скомпилится ли? 2)что выведет?


int main(){
	printf("A\n");
	int a;	
	printf(">%p\n", &a);
	int main(){
	printf(">%p\n", &a);
		a = 1232;
		printf("AA\n");
		char s[50]="3.14 512";
		float f;
		int a;
		sscanf(s,"%f%d", &f, &a);
		sprintf(s, "%d %.1f", a,f);
		printf("%s\n",s);
		printf("BB\n");
		return 0;
	}
	main();
	printf("%d\n", a);
	printf("B\n");
	return 0;
}
