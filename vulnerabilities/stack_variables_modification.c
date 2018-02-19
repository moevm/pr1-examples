#include <stdio.h>
#include <string.h>

int youNeverForceMePrintYes(char *key)
{
	int ret = 123;
	int verySecretKey = 0;
	char buf[8];

	printf("key = %x\n",verySecretKey);

	strcpy(buf,key); //gets() - the same vulnerability

	printf("key = %x\n",verySecretKey);

	if(verySecretKey == 0x41424344)
		printf("Wow! YES!\n");
	else
		printf("I say NOOO!\n");

	return ret;
}

int main()
{
	char s[16] = "12345678DCBA";
	printf("res = %d\n", youNeverForceMePrintYes(s));
	return 0;
}
