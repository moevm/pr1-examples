// using stack in the calculation of the factorial

#include <stdio.h>


int baseESP;
int maxESPOffset = 0;

int getESP()
{
	unsigned int esp;
	__asm__ (	"movl %%esp, %0\n"
				:"=r"(esp) /* выходные операнды */
				: /* входные операнды */
				: /* разрушаемые регистры */
	);
	return esp;
}

int recFact(int n)
{
	int curEsp = getESP();
	if(baseESP - curEsp > maxESPOffset)
		maxESPOffset = baseESP - curEsp;
	
	if(n<=0)
		return 1;
	return n * recFact(n-1);	
}

int iterFact(int n)
{
	maxESPOffset = baseESP - getESP();
	int prod = 1;
	for(int i=2;i<=n;i++)
		prod*=i;
	return prod;	
}

int main()
{
	int res, n = 10;
	baseESP = getESP();
	maxESPOffset = 0;
	res = recFact(n);
	printf("res:%d max esp offset:%d\n", res,maxESPOffset);
	
	maxESPOffset = 0;
	res = iterFact(n);
	printf("res:%d max esp offset:%d\n", res,maxESPOffset);
}
