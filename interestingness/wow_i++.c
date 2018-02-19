#include <stdio.h>

int main(){
  int i = 0;
  i = ++i + i++;
  printf("i = %d\n",i);

  i=0;
  i = 1 + i++;
  printf("i = %d\n",i);

  i=0;
  i = ++i + 1 + ++i;
  printf("i = %d\n",i);
}

/*
gcc:
  i = 3
  i = 1
  i = 4
*/
/*
clang:
  i = 2
  i = 1
  i = 4
*/
/*
vc:
  i = 3
  i = 2
  i = 5
*/

