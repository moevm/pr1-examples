#include <stdio.h>

#define N 5

int main()
{
  int n = 4;
  int a[N]={10, 20, 30, 40};
  int i=0;
  int sum=0;

  for(;i<=n;i++){
    printf("a[%d]=%d; ", i, a[i]);
    sum+=a[i];
  }
  printf("\n sum=%d\n", sum);
  return 0;
}
