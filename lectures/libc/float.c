#include <stdio.h>
#include <float.h>
#include <fenv.h>
#pragma STDC FENV_ACCESS ON
int main()
{
  printf("FLT_MAX = %f\n", FLT_MAX);
  printf("FLT_EPSILON = %.30f\n", FLT_EPSILON);
  printf("FLT_ROUNDS = %d\n", FLT_ROUNDS);
	fesetround(FE_TOWARDZERO);
	printf("FLT_ROUNDS = %d\n", FLT_ROUNDS);
  return 0;
}
