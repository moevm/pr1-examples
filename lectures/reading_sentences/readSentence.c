#include "readSentence.h"

char* readSentence(){
int size = INIT_SIZE;
int length = 0;
char *text = malloc(size*sizeof(char));
int c;

  while ((c = getchar()) != '\n'){
      text[length++]=c;
      if(length == size){
        size += DELTA;
        text = realloc(text, size);
      }
      if(c == '.')
        break;
  }

  if(length>0){
    text[length]='\0';
    return text;
  }
  else{
  free(text);
  return NULL;
  }
}
