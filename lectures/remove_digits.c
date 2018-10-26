#include <stdio.h>
#include <ctype.h>
#include <string.h>

void rmdigits(char *s){
	for(int i=0; s[i];){
		if(isdigit(s[i])){
			memmove(&s[i], &s[i+1], strlen(&s[i]));
//			for(int j=i; s[j]; j++)
//				s[j] = s[j+1]; 
		} else {
			i++;
		}
	}
}

int main(){
	char s[100] = "abc123qweqw87ssd";
	rmdigits(s);
	printf("%s\n",  s);
	
	return 0;
}
