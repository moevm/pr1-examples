#include <stdio.h>

void fun(const float *c){
  //*c = 777; //compilation error: assignment of read-only location ‘*c’
  unsigned long long ull = (unsigned long long) c;
  float *f = (float *) ull;
  *f = 777;
}


int main() {

  float f = 10;
  printf("%f\n",f);
  fun(&f);
  printf("%f\n",f);

return 0;


}
