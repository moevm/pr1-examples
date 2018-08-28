#include <stdio.h>

int main(){

float f = 1.0;
f = f/5;
float a = 0;
a=f*2;

printf("a = %f\n", a);
printf("a == 0.4: %d\n", a ==0.4);
printf("a - 0.4: %f\n", a-0.4);


printf("a = %.20f\n", a);
return 0;


}
