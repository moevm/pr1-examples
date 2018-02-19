// Programming 1. Sample at 2017-03-02-13-55.55
#include <stdio.h>
 
struct Person
{
  const char *name;
  int age;
  void (*print)(const struct Person*);
  void (*printer)(const struct Person*);
} person1, person2;
 
void print_nice(const struct Person *p)
{
  printf("Person %s age %d\n",p->name,p->age);
}
 
void print_ugly(const struct Person *p)
{
  printf("[%s,%d]\n",p->name,p->age);
}
 
void print(const struct Person *obj)
{
  obj->printer(obj);
}
 
 
 
int main(/*int c, char **v */)
{
  person1.name = "Vasya";
  person1.age = 15;
  person1.print = print;
  person1.printer = print_nice;
 
  person2.name = "Petya";
  person2.age = 51;
  person2.print = print;
  person2.printer = print_ugly;
 
  person1.print(&person1);
  person2.print(&person2);
 
  return 0;
}
