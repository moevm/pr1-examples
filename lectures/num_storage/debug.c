#include "debug.h"

void debugStrPrint(char *s){
  for(int i=0; s[i]; i++)
      printf("[%c](%d)\n", s[i], s[i]);
}

