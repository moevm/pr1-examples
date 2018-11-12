#include <stdio.h>

union U{
	struct S1 s;
	char b;
};

int main(){
	union U u;
	u.a = 0;
	u.b = 120;
	printf("%d\n", u.a);

	return 0;
}
