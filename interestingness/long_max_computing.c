#include <stdio.h>
#include <limits.h>
int main(){

	long long_size = 1;
	for (int i = 1; i < sizeof(long_size) * 8 - 1; i++) {
		long_size |= (long)1 << i; // long_size = long_size | ((long)1 << i)
					   // (int) 32 бита -> long_size | 32 бита
					   // (long) 64 бита -> long_size | 64 бита 
	}
	printf("LONG_MAX=%lu, OUR_LONG_MAX=%ld\n", LONG_MAX, long_size);	
	return 0;

}
