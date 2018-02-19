#include <stdio.h>
#define NDEBUG
#include <assert.h>

int main()
{
  int a = 10, b = 0;
  assert(b);
  printf("a/b = %d\n", a/b);
  return 0;
}
