// using stack depending on the parameters

#include <stdio.h>
#include <time.h>

int baseESP;

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

struct data
{
	int a[10];
};

void f(int a)
{
	//int arr[100];
	printf("%d\n",baseESP - getESP());
}

void f1(struct data d)
{
	printf("%d\n",baseESP - getESP());
}

void f3()
{
	printf("%d\n",baseESP - getESP());
}

int main()
{
	struct data d;
	
	baseESP = getESP();
	f(10);
	f1(d);
	f3();
	return 0;
}
