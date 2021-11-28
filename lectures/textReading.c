#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MEM_STEP 5
// size == 5
// (n < size-2)
// (2  < 3
// |0|1|2|3|4|
// |a|b|c| | |

struct Sentence{
	char *str;
	int size; // != strlen(str)
	// ???
};
struct Text{
	struct Sentence **sents;
	int n;
	int size;
};

struct Sentence* readSentence();

struct Text readText(){ // (!) возвращаем не указатель (!)
	int size = MEM_STEP;
	struct Sentence** text= malloc(size*sizeof(struct Sentence*));
	int n=0;
	struct Sentence* temp;
	int nlcount = 0;
	do{
		temp = readSentence();
		if(temp->str[0] == '\n')
			nlcount++;
			// memory leack
		else{ 
			nlcount = 0;
			text[n] = temp;
			n++;
		//	puts(temp->str);
		}
	}while(nlcount<2);
	struct Text txt;
	txt.size = size;
	txt.sents = text;
	txt.n = n;
	return txt;
}

struct Sentence* readSentence(){
	int size = MEM_STEP;
	char *buf = malloc(size*sizeof(char));
	int n=0;
	char temp;
	do{
		if(n >= size-2){
			char *t = realloc(buf, size+MEM_STEP);
			if(!t){ /* ERROR */}
			size+=MEM_STEP;
			buf = t;
//			printf("new size = %d\n",size);
		}
		temp = getchar();
		buf[n]= temp;
		n++;
	}while(temp!='\n' && temp!='.' && temp!='!');
	buf[n]= '\0';
	struct Sentence *sentence = malloc(sizeof(struct Sentence));
	sentence->str = buf;   //(*sentence).str = buf;
	sentence->size = size;
	return sentence;
}

void sentProc(struct Sentence* sent, int k, int m){
//	sent->str === char* == string
	int len = strlen(sent->str);
	char *cur_str = sent->str;
	//
	memmove(cur_str+k, cur_str+k+m, len-m-k+1);
}

int main(){
	struct Text text = readText();
	sentProc(text.sents[0], 2, 5);
	for(int i=0; i<text.n; i++){
	// text.sents[i] === Sentence*
		puts(text.sents[i]->str);
	}
	// Распечатать текст на экран
//1: текст == массив указателей на предл.
//2: каждое предложение == строка
//3: печатать строку мы точно умеем
	return 0;
}
