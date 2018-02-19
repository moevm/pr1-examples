#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

int main()
{

char s[N];
int i;

char *subs = malloc(N * sizeof(char));
//memset(subs, 'A', N-1);

fgets(s, N, stdin);

for(i=0;s[i]!='\n' && s[i]!='!';i++)
  subs[i] = s[i];
//subs[i]='\0';
printf("[%s]\n", subs);

free(subs);
return 0;
}
