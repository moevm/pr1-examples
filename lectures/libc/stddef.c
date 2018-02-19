#include <stddef.h>
#include <stdio.h>
//-fpack-struct
struct car
{
  char brand[31];
  char hp[30];
  double price;
  double tmp;
} t;

int main()
{

	//смещение относительно начала.
	printf("%lu\n", offsetof(struct car, brand));
	printf("%lu\n", offsetof(struct car, hp));
	printf("%lu\n", offsetof(struct car, price));
	printf("%lu\n", offsetof(struct car, tmp));

	printf("\n");
	//размеры членов структуры
//	printf("%lu\n", sizeof (t.brand));
//	printf("%lu\n", sizeof (t.hp));
//	printf("%lu\n", sizeof (t.price));
//	printf("%lu\n", sizeof (t.tmp));

	// размер занимаемый структурой в памяти.
	printf("sizeof struct = %lu\n", sizeof(struct car));

}

