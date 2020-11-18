#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// how many letters 1 block wil contain
#define BUFF_SZ 100

// how many BLOCKS text contains
#define TEXT_BLOCKS 10

int main()
{
    // allocate memory for 1 block
    char** text=calloc(TEXT_BLOCKS,sizeof(char*));
    char c;

    // main loop, each time geting letter from stdin. You can use another loop break condition instead "\n", EOF for e.g
    while((c=getchar())!='\n')
    {
        // here you need to fill up "text" by blocks of chars that you read from stdin and extend "text" 

        // do the work
    }

    return 0;
}
