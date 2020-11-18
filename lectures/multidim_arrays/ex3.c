#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 4

void print_2darr(char** a, int size) {
    printf("ARRAY PRINT:\n");
    for(int i=0; i<size; i++) {
        printf("a[%d]: '",i);
        for(int j=0; j < strlen(a[i]); j++)
            printf("%c", a[i][j]);
        printf("'\n");
    }
}

int main() {
    
    // динамическая строка 
    char* rocket = (char *)calloc(15, sizeof(char)); 
    char s1[] = "shuttle";
    char s2[] = "buran";
    char s3[] = "falcon9";

    printf("[%s]\n", s1);

    // выделяем память под двумерный динамический массив 
    char** rockets = (char **)calloc(SIZE, sizeof(char*)); 
    
    for(int i=0; i < SIZE; i++) {
        rockets[i] = (char*)calloc(20, sizeof(char));
    }
    
    // копируем в массив ракеты
    strncpy(rockets[0], s2, strlen(s2));
    strncpy(rockets[1], s3, strlen(s3));

    print_2darr(rockets, SIZE);

    // жалеем ОЗУ
    for(int i=0; i < SIZE; i++) 
        free(rockets[i]);
    free(rockets);
    
    return 0;
}
