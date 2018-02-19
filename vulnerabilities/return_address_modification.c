#include <stdio.h>
#include <string.h>

void iAmNotChatterbox(char *key)
{
	printf("I will not tell you anything!!!\n");	
	char buf[8];
	strcpy(buf,key); //gets() - the same vulnerability
}

void doAnything()
{
	printf("I can do anything for you!!\n");
}

int main()
{
	char s[32];
	int i;
	for(i=0;i<20;i++)
		s[i] = 'A';

	s[i++] = 0x66;
	s[i++] = 0x84;
	s[i++] = 0x04;
	s[i++] = 0x08;
	s[i]   = 0x00;	 
	iAmNotChatterbox(s);
	printf("bye!\n");
	return 0;
}
