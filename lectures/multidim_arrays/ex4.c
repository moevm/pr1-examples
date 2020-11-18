#include <stdio.h>
#include <stdlib.h>

#define I 2
#define J 4
#define K 6

int main ()
{

    int mtrx[2][2] = {{1,1}, {2,2}};

    // статический 3d массив
    int array[I][J][K];
    int i, k, n, c;
    for (i=0; i<I; i++)
    {
        printf("[%dx%d]\n", J, K);
        for (k=0; k<J; k++)
        {
            c = 1;
            for (n=0; n<K; n++)
                printf("% 2d", array[i][k][n] = c++);
            printf("\n");
        }
        printf("\n");
    }

    // динамический 3d массив
    printf("FLOAT ARRAY:\n");
    float*** farray = (float***)calloc(I, sizeof(float**));
    for (i=0; i<I; i++)
    {
        farray[i] = (float**)calloc(J, sizeof(float*));
        printf("[%dx%d]\n", J, K);
        for (k=0; k<J; k++)
        {
            farray[i][k] = (float*)calloc(K, sizeof(float));
            c = 1;
            for (n=0; n<K; n++)
                printf("% 4f", farray[i][k][n] = c++);
            printf("\n");
        }
        printf("\n");
    }

    // ...
    for (i=0; i<I; i++)
    {
        for (k=0; k<J; k++)
            free(farray[i][k]);    
        free(farray[i]);
    }
    free(farray);

    return 0;
}
