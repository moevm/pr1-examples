#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Sentence{
    char *s;
    int size;
} Sentence;

typedef struct Text{
    struct Sentence *sentences;
    int size;
    int len;
} Text;

Text initText(){
    Text text;
    text.size = 5;
    text.len = 0;
    text.sentences = malloc(text.size * sizeof(Sentence));
    return text;
}

void addSentence(Text *text, Sentence sentence){
    if(text->len == text->size){
        text->size+=10;
        text->sentences = realloc(text->sentences, text->size * sizeof(Sentence)); //!!!!
    }
    text->sentences[text->len++] = sentence;
}

Sentence readSentence(){
    Sentence sentence;
    sentence.size = 10;
    sentence.s = calloc(sentence.size, sizeof(char));
    int i=0;
    int c;
    do{
        c = getchar();
        if(c == ' ' && i == 0){
            continue;
        }
        sentence.s[i++] = c;
        if(i==sentence.size){
            sentence.size+=10;
            sentence.s = realloc(sentence.s, sentence.size * sizeof(char)); // !!!
        }
    } while (!strchr(".?!\n", c));
    sentence.s[i] = '\0';
    return sentence;
}

void freeText(Text *text){
    for(int i=0; i<text->len; i++){
        free(text->sentences[i].s);
    }
    free(text->sentences);
}

int main(){

    Text text = initText();
    Sentence sentence;
    int stop = 0;
    do{
        sentence = readSentence();
        if(sentence.s[0] == '\n'){
            free(sentence.s);
            stop = 1;
        } else {
            addSentence(&text, sentence);
        }

    } while (!stop);

    for(int i=0; i<text.len; i++){
        printf("[%s]\n", text.sentences[i]);
    }

    freeText(&text);

    return 0;
}
