#include <stdio.h>
#include <tgmath.h>
#include <math.h>

int main() {

    double dx=0, dy=0;
    float fx = 0, fy = 0;
    long double complex clx = 1.0 - 0.0 * I;
    long double complex cly = -1.0 - 0.0 * I;

    dy = sin(dx);   //dy = sin(dx)
    fy = sin(fx);   //fy = sinf(fx)
    cly = sin(clx); //cly = csinl(clyx)
    return 0;
}
