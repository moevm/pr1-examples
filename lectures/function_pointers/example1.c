// Programming 1. Sample at 2017-03-02-13-55.55
#include <stdio.h>
 
struct Person
{
  const char *name;
  int age;
} person;
 
void print_nice(const struct Person *p)
{
  printf("Person %s age %d\n",p->name,p->age);
}
 
void print_ugly(const struct Person *p)
{
  printf("[%s,%d]\n",p->name,p->age);
}
 
void print(const struct Person *obj, 
  void (*printer)(const struct Person*))
{
  printer(obj);
}
 
int main(/*int c, char **v */)
{
  person.name = "Vasya";
  person.age = 15;
 
  print(&person,print_nice);
  print(&person,print_ugly);
 
  return 0;
}
