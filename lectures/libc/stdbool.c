#include <stdio.h>
#include <stdbool.h>

int main()
{
  _Bool b = false;
  if(b){
    printf("b\n");
  }
  if(!b){
    printf("!b\n");
  }

  if(true && !false){
    printf("_Bool is cool!\n");
  }

  return 0;
}
