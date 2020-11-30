#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_strlen(char* str) {
    
    int i = 0;
    while(str[i] != '\0')
        i++;
    return i;
}

// хотим изменить переменную
void plus10(int* a) {
    *a += 10;
}

void replace_ones(char** text) {

    char* s = *text;
    int i = 0; 
    while(s[i] != '\0') {
        if(s[i] == '1')
            s[i] = '9';
        i++;
    }
}

char* gen_name() {
    char*name  = "Moisei";

    // some work
    return name;
}

char* gen_animal() {
    char* s = (char*)calloc(20, sizeof(char));
    strncpy(s, "Bear", 20);
    return s;
}

int main() {

    char* s = (char*)calloc(20, sizeof(char));
    strncpy(s, "Ya11hoo111", 20);
    printf("LEN: %d\n", my_strlen(s));
    
    // изм. аргумента
    int b = 40;
    plus10(&b);
    printf("B val: %d\n", b);
    
    // изм. строки
    printf("NATIVE: [%s]\n", s);
    replace_ones(&s);
    printf("REPLACED: [%s]\n", s);

    //char* s2 = "ta111pok";
    //replace_ones(&s2);

    // изм. разных строк
    char* name = gen_name();
    char* animal = gen_animal();
    
    printf("NAME: [%s]\n", name);
    printf("ANIMAL: [%s]\n", animal);
    //name[0] = 'M';
    animal[0] = 'M';
    printf("ANIMAL: [%s]\n", animal);

    return 0;
}
