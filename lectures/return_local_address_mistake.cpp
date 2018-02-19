#include <stdio.h>

int * getValue(float v)
{
	int value = (int )v;
	int *s = &value;
	return s;
}

void g()
{
	char d[100];
	for(int i=0;i<100;i++)
		d[i]=i;

	printf("%s\n",d);
}

int main()
{
	int *v = getValue(3.14);
	printf("value = %d\n", *v);
	g();	
	printf("value = %d\n", *v);

}
