#include <stdio.h>
#include <stdlib.h>

int main() {
    
    // одномерный динамический массив
    int* secret_code_flatten = (int *)calloc(8, sizeof(int)); 

    secret_code_flatten[3] = 3;

    printf("Flatten[0]: %d\n", secret_code_flatten[0]);
    printf("Flatten[3]: %d\n", secret_code_flatten[3]);

    // двумерный динамический массив 
    int** secret_code_double = (int **)calloc(2, sizeof(int*)); 
    
    printf("Double[0]: %p\n", secret_code_double[0]);

    
    for(int i=0; i < 2; i++) {
        secret_code_double[i] = (int*)calloc(4, sizeof(int));
        secret_code_double[i][0] = 6;
        secret_code_double[i][2] = 4;
    }

    printf("_________________________________\n");
    printf("Double[0][2]: %d\n", secret_code_double[0][2]);
    printf("Double[1][2]: %d\n", secret_code_double[1][2]);

    // освобождение памяти, куда же без него
    for(int i=0; i < 2; i++) 
        free(secret_code_double[i]);
    free(secret_code_double);

    return 0;
}
