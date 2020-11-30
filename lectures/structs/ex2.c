#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

struct Point3D {

    char name;
    int x;
    int y;

};

struct Graph {

    char* title;
    struct Point3D* pts;

};

typedef struct Point3D Point3D;
typedef struct Graph Graph;

int main() {

    // размер структуры
    printf("Struct GRAPH holds %ld bytes\n", sizeof(Graph));

    Graph g;

    // выделение памяти и инициализация
    printf("Struct GRAPH holds %p in [pts] field BEFORE alloc\n", g.title);

    g.title = (char*)calloc(100, sizeof(char));
    g.pts = (Point3D*)calloc(SIZE, sizeof(Point3D));

    // заполнение поля title
    strncpy(g.title, "Dependence of the number of platypuses on the volume of quacking in the spring", 100);

    printf("Struct GRAPH holds [%s] in [pts] field\n", g.title);
    
    // заполнение массива pts
    for(int i=0; i<SIZE; i++) {
        g.pts[i].name = 65+i;
        g.pts[i].x = i;
        g.pts[i].y = i*2;
        printf("GRAPH pts[%d]: [%c, %d, %d] \n", i, g.pts[i].name, g.pts[i].x,g.pts[i].y);
    }
    
    // все помнят про освобождение памяти как отче наш?
    free(g.title);
    free(g.pts);

    return 0;
}
