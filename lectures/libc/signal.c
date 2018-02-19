#include <stdio.h>
#include <signal.h>

void ctrlc(int signal){
  printf("Nope!\n");
}

int main()
{
  //signal(SIGINT,ctrlc);
  while(1){
    raise(SIGINT);
  }
  return 0;
}
