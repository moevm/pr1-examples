#include <stdio.h>

int main() {
    
    // one-dim array
    int secret_code[] = {1,2,3,4}; 

    printf("secret_code[0]: %d\n", secret_code[0]);

    // sec-dim arraym list-initialized
    int disp[2][4] = {
        {10, 11, 12, 13},
        {14, 15, 16, 17}
    };

    printf("disp[0][0]: %d\n", disp[0][0]);
    
    return 0;
}
