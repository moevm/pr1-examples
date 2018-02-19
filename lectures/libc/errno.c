#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <math.h>

int main()
{
  FILE *f = fopen("no_such_file.txt", "r");
  if(!f)
    perror("Error: ");
  errno = 0;
  perror("No error: ");
  sqrt(-10);
  perror("Error: ");

  return 0;
}
