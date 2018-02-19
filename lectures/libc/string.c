#include <stdio.h>
#include <string.h>

#define PRINT_STR(X) printf(#X" = %s\n", X)

int main()
{

/*
void    *memccpy(void *, const void *, int, size_t);
void    *memchr(const void *, int, size_t);
int      memcmp(const void *, const void *, size_t);
void    *memcpy(void *, const void *, size_t);
void    *memmove(void *, const void *, size_t);
void    *memset(void *, int, size_t);
===========
char    *strcat(char *, const char *);
char    *strchr(const char *, int);
int      strcmp(const char *, const char *);
int      strcoll(const char *, const char *);
char    *strcpy(char *, const char *);
size_t   strcspn(const char *, const char *);
char    *strdup(const char *);
char    *strerror(int);
size_t   strlen(const char *);
char    *strncat(char *, const char *, size_t);
int      strncmp(const char *, const char *, size_t);
char    *strncpy(char *, const char *, size_t);
char    *strpbrk(const char *, const char *);
char    *strrchr(const char *, int);
size_t   strspn(const char *, const char *);
char    *strstr(const char *, const char *);
char    *strtok(char *, const char *);
char    *strtok_r(char *, const char *, char **);
size_t   strxfrm(char *, const char *, size_t);
*/

// void *memccpy(void *s1, const void *s2, int c, size_t n);
// Descr: The memccpy() function copies bytes from memory area s2 into s1, stopping after the first occurrence of byte c (converted to an unsigned char) is copied, or after n bytes are copied, whichever comes first. If copying takes place between objects that overlap, the behaviour is undefined.
// Ret: The memccpy() function returns a pointer to the byte after the copy of c in s1, or a null pointer if c was not found in the first n bytes of s2.
    //char s1[30]={0};
    //char s2[]="What a nice string for memccpy function!";
    //char *res = memccpy(s1,s2,'s', 20);
    //printf("%zd\n", res-s1); // 13
    //PRINT_STR((char*)memccpy(s1,s2,'!', 20)); // (null)

// void *memchr(const void *s, int c, size_t n);
// Descr: The memchr() function locates the first occurrence of c (converted to an unsigned char) in the initial n bytes (each interpreted as unsigned char) of the object pointed to by s.
// Ret: The memchr() function returns a pointer to the located byte, or a null pointer if the byte does not occur in the object.

    //char s[]="What a nice string for memchr function!";
    //char *pch;
    //pch = (char*) memchr (s, 's', strlen(s));
    //if (pch!=NULL)
    //  printf ("'s' index %zd.\n", pch-s);
    //else
    //  printf ("'s' not found.\n");

/*
    char str[] = "memmove can be very useful......";
    memmove (str+20,str+15,11);
    printf("after memmove str = {%s}\n", str);

    char *p = memchr(str, 'v', 30);
    if(p){
        printf("memchr result = {%s}\n", p);
    }

    memset(str, 65, 10);
    printf("after memset str = {%s}\n", str);

    printf("strerror(0) = %s\n", strerror(0));

    printf("strspn(\"lets see how it works!\", \"etsl \") = %zd\n", strspn("lets see how it works!", "etsl "));

    printf("strpbrk(\"Some text& with ? some # signs \", \"?#&\") = %s\n", strpbrk("Some text& with ? some # signs ", "?#&"));


    char info[]="Tom.Sawyer,12:Mark;Twain";
    p = strtok(info,";:.,");
    while(p){
        printf(">{%s}\n", p);
        p = strtok(NULL,";:.,");
    }

    printf("strsignal(9) = %s\n", strsignal(9));

*/
    return 0;
}
