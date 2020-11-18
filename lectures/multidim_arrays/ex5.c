#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// how many letters 1 block wil contain
#define BUFF_SZ 100

// this ex. doesn't working natively

int main()
{
    // allocate memory for 1 block
    char* text=calloc(BUFF_SZ,sizeof(char));
    char c;

    // main loop, each time geting letter from stdin. You can use another loop break condition instead "\n", EOF for e.g
    while((c=getchar())!='\n')
    {
        // here you need to fill up "text" string by letters and extend "text" 

        // do the work
    }

    printf("[%s]", text);
    
    return 0;
}
