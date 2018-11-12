#include <stdio.h>


struct Point{
	int x;
	char s[30];
	char *s;
	int y;
};

void printPoint(const struct Point *p){
	printf("(%d;%d)\n", (*p).x, p->y);
}

struct Point createPoint(int x, int y){
	struct Point p1 = {x, y};
	return p1;
}



int main(){
	struct Point p = createPoint(123,77);
	printPoint(&p);
//	p.x = 10;
//	p.y = 11;
	return 0;
}
