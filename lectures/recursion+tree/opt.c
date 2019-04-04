#include <stdio.h>

void f(int n){
	if(n<=0)
		return;
	puts("hello");
	f(n-1);
}

int main(){
	f(6);

return 0;
}
