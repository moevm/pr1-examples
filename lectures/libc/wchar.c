#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <locale.h>

int main()
{
    char s[100];
   printf(">>%d\n",fwide (stdout,0));
    printf(">>%d\n",fwide (stdout,0));
//    fgets(s, 100, stdin);
//  printf("{%s}\n",s);
//    printf("strlen(s) = %zd\n",strlen(s));
//    for(int i=0;i<strlen(s);i++)
//        printf("'%c'(%d)", s[i], s[i]);
//    printf("\n");

    setlocale(LC_ALL,"");
    wchar_t ws[100];
    fgetws(ws,100,stdin);
    wprintf(L"{%ls}\n",ws);
//    printf("wcslen(ws) = %zd\n",wcslen(ws));
    wprintf(L"wcslen(ws) = %zd\n",wcslen(ws));
    return 0;
}
