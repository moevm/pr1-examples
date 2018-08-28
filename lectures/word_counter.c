#include <stdio.h>
#include <ctype.h>

int main(int argc, char **argv) {
    FILE *file = fopen("t.txt","r");

    if(NULL == file)
        return 0;

    int prev = ' ';
    int cur;
    int wcount = 0;
    do {
        cur = fgetc (file);
        if(cur == EOF)
            break;
        printf("%c[%d]\n",cur,cur);
        if (isspace(cur))
            if(!isspace(prev)){
                wcount++;
            }
        prev = cur;
    } while (cur != EOF);
    fclose (file);
    if(!isspace(prev))
        wcount++;
    printf ("The file contains %d words\n",wcount);

    return 0;
}
