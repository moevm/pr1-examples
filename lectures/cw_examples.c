#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

#define INIT 10

struct Text{
	wchar_t **buf;
	int size;
	int n;
};

wchar_t* readSentence(){
	int size = INIT;
	int n = 0;
	wchar_t* buf = malloc(size * sizeof(wchar_t));
	wchar_t wc;
	do{
		wc = fgetwc(stdin);
		buf[n] = wc;
		n++;
		if(n == size - 2){
			size+=INIT;
			buf = realloc(buf, size * sizeof(wchar_t));
		}
	}while(!wcschr(L"!?.\n", wc));
	buf[n] = L'\0';
	return buf;
}

struct Text readText(){
	int size = INIT;
	int n = 0;
	int nc = 0;
	wchar_t** buf = malloc(size * sizeof(wchar_t*));
     while(1){
         wchar_t *ws = readSentence();
         if(ws[0]==L'\n'){
            nc++;
			free(ws);
		}
         else{
            nc = 0;
			buf[n] = ws;
			n++;
			if(n == size - 2){
				size+=INIT;
				buf = realloc(buf, size * sizeof(wchar_t*));
			}
		}
         if(nc == 2)
             break;
     }
	struct Text text; // text ={buf,size,n}
	text.buf = buf;
	text.size = size;
	text.n = n;
	return text;	

}


int cmp (const void * a, const void * b)
{
	wchar_t* aa = *((wchar_t**)a);
	wchar_t* bb = *((wchar_t**)b);
	return wcscmp(aa, bb);
}

int main()
{
	setlocale(LC_ALL,"");
/*	struct Text text = readText();
	for(int i=0; i<text.n; i++)
		wprintf(L"%ls\n",text.buf[i]);	

*/
  wchar_t wcs[] = L"- qwe This, a sample string aaa B QZZ";
  wchar_t * pwc;
  wchar_t *tmp;
  wchar_t* arr[10];
 int n=0;
  pwc = wcstok (wcs,L" ,.-", &tmp);
  while (pwc != NULL)
  {	
	arr[n] = pwc;
	n++;
    pwc = wcstok (NULL,L" ,.-", &tmp);
  }

	qsort(arr, n, sizeof(wchar_t*), cmp);

	for(int i=0; i<n; i++)
    	wprintf (L"{%ls}\n",arr[i]);
	
	

	return 0;
}
