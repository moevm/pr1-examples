#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void var(char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	if(!strcmp(format, "%d"))
	{
		int x = va_arg (ap, int);
		printf ("You passed decimal object with value %d\n", x);
	}

	if(!strcmp(format, "%s"))
	{
		char *p = va_arg (ap, char *);
		printf ("You passed c-string \"%s\"\n", p);
	}

  if(!strcmp(format, "%2int"))
  {
    int a = va_arg (ap, int);
    int b = va_arg (ap, int);

    printf ("You passed 2int: %d, %d\n", a,b);
  }
	va_end (ap);
}

int main(void)
{
	var("%d", 255);
	var("%s", "test string");
  var("%2int", 100, 200);
	return 0;
}
