#include <stdio.h>
#include <fenv.h>
#include <math.h>

#pragma STDC FENV_ACCESS ON

int main()
{
  double one = 1.0;
  double zero = 0.0;
  feclearexcept(FE_ALL_EXCEPT);
  printf("1.0/0.0 = %lf\n", one/zero);
    if(fetestexcept(FE_DIVBYZERO)) {
        printf("division by zero\n");
    } else {
        printf("no divsion by zero\n");
    }
    feclearexcept(FE_ALL_EXCEPT);
    printf("1.0/10 = %lf\n", one/10);
    if(fetestexcept(FE_INEXACT)) {
        printf("inexact result\n");
    } else {
        printf("no inexact result\n");
    }

    feclearexcept(FE_ALL_EXCEPT);
    printf("sqrt(-1) = %lf\n",sqrt(-1));
    if(fetestexcept(FE_INVALID)) {
        printf("invalid result\n");
    } else {
        printf("no invalid result\n");
    }
}
