#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fnExit1 (void)
{
  puts ("Exit function 1.");
}

void fnExit2 (void)
{
  puts ("Exit function 2.");
}

int main()
{
//  atexit (fnExit1);
//  atexit (fnExit2);

//  while(1){}

  char ff[]="3.1415";
  float f;
  f = atof(ff);
  //printf("f = %f\n", f);
  srand(time(NULL));
  //printf("%d\n", rand());
  //printf("%d\n", rand());

  system("gnome-mahjongg &");

  div_t d = div(107, 25);
  printf("[%d;%d]\n", d.quot, d.rem);
  return 0;
}
