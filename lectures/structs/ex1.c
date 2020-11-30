#include <stdio.h>

struct Point3D {

    char name;
    int x;
    int y;

};


struct Point {

    char name[9];
    int x;
    int y;

};

//кл.сл.  тип данных    alias
typedef struct Point3D Point3D;

int main() {
    
    // list init
    Point3D p1 = {'A', 4, 5};
    
    // field init
    struct Point3D p2;
    p2.name = 'B';
    p2.x = -2;
    p2.y = 1;

    // from ptr
    Point3D* p3 = &p2;

    // Размер структуры в байтах
    printf("Struct holds %ld bytes\n", sizeof(p1));
    printf("Name p2: %c \n", p2.name);
    printf("Name p2 (p3->name): %c \n", p3->name);

    printf("LEN: [%d]", sizeof(struct Point));

    return 0;
}
