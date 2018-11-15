#include <stdio.h>
#include <stdlib.h>

int predicat(int a){
	return a%2;
}

int summPred(int *a, int n, int(*pred)(int)){
	int sum = 0;
	for(int i=0; i<n; i++)
		if(pred(a[i])){
			sum+=a[i];
		}
	return sum;
}
// int sum = summPred(arr, n, predicat);
struct Person{
	char surname[50];
	char name[50];
	void (*printer)(struct Person);
};
void printFull(struct Person p){
	printf("%s %s\n", p.surname, p.name);
}
void printShort(struct Person p){
	printf("%s %c.\n", p.surname, *p.name);
}
void printAll(struct Person *ps, int n){
	for(int i=0; i<n; i++)
		ps[i].printer(ps[i]);
}
int main(){
	struct Person ps[]={
							{"Aaa", "Bbb", printShort},
							{"Ccc", "Ddd", printFull},
							{"Eee", "Fff", printFull}
							};

	printAll(ps, sizeof(ps)/sizeof(struct Person));
	return 0;
}
