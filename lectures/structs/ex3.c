#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// базовая цель -- разный тип доступа к данным, хорошо для машинно-независимого кода
union Int {
    int digit;
    char bin[sizeof(int)];
    double val;
};

typedef union Int Int;

int main() {

    Int a;
    a.digit = 4000;
    a.val = 20;

    printf("Union size: [%ld]\n", sizeof(Int));
    printf("Double: [%f]\n", a.val);
    printf("Digit: [%d], Binary: [%d, %d, %d, %d]\n", a.digit, a.bin[0], a.bin[5], a.bin[6], a.bin[7]);
    
    return 0;
}
