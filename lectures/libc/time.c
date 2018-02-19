#include <stdio.h>
#include <time.h>
#include <math.h>

int main()
{



  printf("%ju\n",clock());
  //for(long long i=0;i<1000000000;i++)sqrt(10);
  printf("%ju\n", clock()/CLOCKS_PER_SEC);

  time_t rawtime;
  time (&rawtime);
  printf("%ju\n",rawtime);
  printf("%s", ctime(&rawtime));

  struct tm * timeinfo;
  timeinfo = localtime (&rawtime);
  printf("%s", asctime(timeinfo));
  timeinfo->tm_mon = 0;
  printf("%s", asctime(timeinfo));

  rawtime = 0;
  printf("%s", ctime(&rawtime));


  return 0;
}
