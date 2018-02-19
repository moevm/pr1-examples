#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
int main()
{
  int32_t a = 100;
  intmax_t max = INTMAX_MAX;
  printf("%"PRId32"\n", a);
  printf("%jd\n", max);
  return 0;
}
