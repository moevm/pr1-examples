#include <stdio.h>
#include "readSentence.h"

int main()
{
char *s;
while(s = readSentence()){
  printf("[%s]\n", s);
  free(s);
}

return 0;
}
