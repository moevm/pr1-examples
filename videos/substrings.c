#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ins(char *s, char *sub_s, int ins_i){
    memmove(s+ins_i+strlen(sub_s), s+ins_i, strlen(s)-ins_i+1);
    memcpy(s+ins_i, sub_s, strlen(sub_s));
}

void rem_sub_s(char *s, int rm_i, int rm_len){
    memmove(s+rm_i, s+rm_i+rm_len, strlen(s)-(rm_i+rm_len)+1);
}

int main(){
    int s_size=20;
    char *s = malloc(s_size*sizeof(char));
    char sub_s[]="666";
    strcpy(s, "abcdefg");
    if(strlen(s)+ strlen(sub_s) >= s_size){
        s_size = strlen(s) + strlen(sub_s) + 1;
        s = realloc(s, s_size);
    }
    ins(s, sub_s, 2);
    puts(s);
    rem_sub_s(s, 2, 3);
    puts(s);
    return 0;
}
