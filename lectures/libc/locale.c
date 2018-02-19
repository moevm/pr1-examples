#include <stdio.h>
#include <locale.h>
#include <time.h>

int main()
{
  setlocale(LC_ALL, "");

  struct lconv* currentlocale;
  struct tm * timeinfo;
  time_t rawtime;
  char buffer [80];

  currentlocale = localeconv();
  printf("currentlocale->decimal_point is '%c'\n", *(currentlocale->decimal_point));

  time (&rawtime);
  timeinfo = localtime (&rawtime);

  strftime (buffer,80,"Now it's %c.",timeinfo);
  printf("%s\n",buffer);

  return 0;
}
