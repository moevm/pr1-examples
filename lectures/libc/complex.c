#include <stdio.h>
#include <complex.h>

int main() {

    double complex z1 = 1.0 + 3.0 * I;
    double complex z2 = 1.0 - 4.0 * I;

    printf("Z1 \t= %.2f + %.2fi\nZ2 \t= %.2f %+.2fi\n", creal(z1), cimag(z1), creal(z2), cimag(z2));

    double complex sum = z1 + z2;
    printf("Z1 + Z2 = %.2f %+.2fi\n", creal(sum), cimag(sum));

    double complex difference = z1 - z2;
    printf("Z1 - Z2 = %.2f %+.2fi\n", creal(difference), cimag(difference));

    double complex product = z1 * z2;
    printf("Z1 x Z2 = %.2f %+.2fi\n", creal(product), cimag(product));

    double complex quotient = z1 / z2;
    printf("Z1 / Z2 = %.2f %+.2fi\n", creal(quotient), cimag(quotient));

    double complex conjugate = conj(z1);
    printf("Z1 \t= %.2f %+.2fi\n", creal(conjugate), cimag(conjugate));

    return 0;
}
