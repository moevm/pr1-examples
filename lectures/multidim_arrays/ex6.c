#include <stdio.h>
#include <stdlib.h>


int global;

void static_array_example() {
	int array[100][20][3]; // sizeof(int) * 100 * 20 * 3
	printf("Static array info:\n");
	printf("-- size: %ld\n", sizeof(array));
	printf("-- ptr: %p\n", array);
	printf("-- first elem ptr: %p\n", &array[0][0][0]);
	printf("-- last elem ptr: %p\n", &array[99][19][2]);
	printf("-- last elem ptr (correct too): %p\n", ((int *)array) + (100 * 20 * 3) - 1);
	printf("-- last-first diff: %ld\n", (((int *)array) + (100 * 20 * 3) - 1) - (int *)array);

	printf("array[0][0][2]=%p | array + 2=%p\n", &array[0][0][2], ((int *)array) + 2); // [x, x, x][x, x, x] * 20 * 100
											   											  
	printf("Char ptr arithm: ptr (%p), ptr + 2 (%p)\n", (char *)array, ((char *)array) + 2); // (char *)ptr + 1 == ptr + 1 * sizeof(char) -> +1
	printf("Int ptr arithm: ptr (%p), ptr + 2 (%p)\n", (int *)array, ((int *)array) + 2);// (int *)ptr + 1 == ptr + 1 * sizeof(int) -> +4
	printf("Char * ptr arithm: ptr (%p), ptr + 2 (%p)\n", (char **)array, ((char **)array) + 2);// (char **)ptr + 1 == ptr + 1 * sizeof(char *) -> +8

}

void dynamic_array_example() {
	int ***array = calloc(100, sizeof(int **));
	for (int i=0; i < 100; i++) {
		array[i] = calloc(20, sizeof(int *));
		for (int j=0; j < 20; j++) {
			array[i][j] = calloc(3, sizeof(int)); // array + 5 -- seg fault
		}
	}
	printf("Dynamic array info:\n");
	printf("-- size: %ld\n", sizeof(array)); // wrong
	printf("-- ptr: %p\n", array);
	printf("-- first elem ptr: %p|%p\n", **array, &array[0][0][0]);
	printf("-- last elem ptr: %p|%p\n", &array[99][19][2], ((int *)*((int **)*((int ***)array + 99) + 19) + 2));
	printf("-- last elem ptr (wrong): %p\n", ((int *)array) + (100 * 20 * 3) - 1);
	printf("-- last-first diff: %ld\n", &array[99][19][2] - (int *)array);
	
	for (int i=0; i < 100; i++) {
		for (int j=0; j < 20; j++) {
			free(array[i][j]);
		}
		free(array[i]);
	}
	free(array);
}

int main() {
	static_array_example();
	dynamic_array_example();
	return 0;
}
