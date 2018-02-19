#include <stdio.h>
#include <math.h>

#define DEG_TO_RAD(x) x/180.0*M_PI

int main()
{

  printf("ceil(1.5) = %f\n", ceil(1.5));
  printf("floor(1.5) = %f\n", floor(1.5));
  printf("fmod(5.0, 2.0) = %f\n", fmod(5.0, 2.0));
  printf("log10(1024) = %f\n", log10(1024));
  printf("sin(PI) = %f\n", sin(M_PI_2));
  printf("sin(PI) = %f\n", sin(DEG_TO_RAD(30)));
  return 0;
}
