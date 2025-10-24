#include <stdio.h>

int main() {
    // Целочисленные типы
    int integerVar = 42; // Создание переменной integerVar с типом int (обычно от -2,147,483,648 до 2,147,483,647).
    unsigned int unsignedVar = 100; // Беззнаковое целое число (обычно от 0 до 4,294,967,295).
    short shortVar = -1234; // Короткое целое число (обычно от -32,768 до 32,767).
    unsigned short unsignedShortVar = 5678; // Беззнаковое короткое целое число (обычно от 0 до 65,535).
    long longVar = -123456789L; // Длинное целое число (обычно от -2,147,483,648 до 2,147,483,647, но может совпадать с int или быть шире).
    unsigned long unsignedLongVar = 987654321UL; // Беззнаковое длинное целое число (обычно от 0 до 4,294,967,295, но может совпадать с unsigned int или быть шире).
    long long longLongVar = -123456789012345LL; // Очень длинное целое число (обычно от -9,223,372,036,854,775,808 до 9,223,372,036,854,775,807).
    unsigned long long unsignedLongLongVar = 987654321098765432ULL; // Беззнаковое очень длинное целое число (обычно от 0 до 18,446,744,073,709,551,615).

    // Типы с плавающей точкой (числа с дробной частью, не целые)
    float floatVar = 3.141592f; // Число с плавающей точкой одинарной точности (примерно 7 значащих цифр, диапазон от ±1.175494351e-38 до ±3.402823466e+38).
    double doubleVar = 3.141592653589793; // Число с плавающей точкой двойной точности (примерно 15 значащих цифр, диапазон от ±2.2250738585072014e-308 до ±1.7976931348623158e+308).
    long double longDoubleVar = 3.141592653589793238L; // Число с плавающей точкой расширенной точности (зависит от платформы, обычно больше, чем double).

    // Символьный и строковый типы
    char charVar = 'A'; // Символьная переменная (один байт, от -128 до 127 или от 0 до 255) -- ASCII символы.
    char stringVar[] = "Hello, World!"; // Строковая переменная (массив символов, заканчивающийся нулевым символом '\0').

    // Указатель на переменную integerVar
    int *pointerVar = &integerVar; // Указатель, хранящий адрес переменной integerVar.

    // Вывод целочисленных типов
    printf("Целочисленные типы:\n");
    // "%%d" выводит символы %d.
    // "\n"  символ перевода на новую строку
    printf("  %%d: %d (int)\n", integerVar);  // Вывод переменной integerVar типа int в виде %d: <значение> (int).
    printf("  %%u: %u (unsigned int)\n", unsignedVar);  // Вывод переменной unsignedVar типа unsigned int.
    printf("  %%hd: %hd (short)\n", shortVar);  // Вывод переменной shortVar типа short.
    printf("  %%hu: %hu (unsigned short)\n", unsignedShortVar);  // Вывод переменной unsignedShortVar типа unsigned short.
    printf("  %%ld: %ld (long)\n", longVar);  // Вывод переменной longVar типа long.
    printf("  %%lu: %lu (unsigned long)\n", unsignedLongVar);  // Вывод переменной unsignedLongVar типа unsigned long.
    printf("  %%lld: %lld (long long)\n", longLongVar);  // Вывод переменной longLongVar типа long long.
    printf("  %%llu: %llu (unsigned long long)\n", unsignedLongLongVar);  // Вывод переменной unsignedLongLongVar типа unsigned long long.

    // Вывод типов с плавающей точкой
    printf("\nТипы с плавающей точкой:\n");
    printf("  %%f: %f (float)\n", floatVar);  // Вывод переменной floatVar типа float.
    printf("  %%lf: %lf (double)\n", doubleVar);  // Вывод переменной doubleVar типа double.
    printf("  %%Lf: %Lf (long double)\n", longDoubleVar);  // Вывод переменной longDoubleVar типа long double.
    printf("  %%e: %e (float в экспоненциальной форме)\n", floatVar);  // Вывод переменной floatVar в экспоненциальной форме.
    printf("  %%g: %g (автоматический выбор между %%f и %%e)\n", floatVar);  // Вывод переменной floatVar в формате %g (автоматический выбор между %f и %e в зависимости от величины числа: %f для обычных чисел, %e для очень больших или очень маленьких).

    // Вывод символьного и строкового типов
    printf("\nСимвольный и строковый типы:\n");
    printf("  %%c: %c (char)\n", charVar);  // Вывод переменной charVar типа char.
    printf("  %%s: %s (string)\n", stringVar);  // Вывод строки stringVar.

    // Вывод указателей
    printf("\nУказатели:\n");
    printf("  %%p: %p (указатель)\n", (void*)pointerVar);  // Вывод адреса, хранящегося в указателе pointerVar.
    printf("  Значение по указателю: %d (значение integerVar через pointerVar)\n", *pointerVar);  // Вывод значения переменной integerVar через разыменование указателя pointerVar.

    return 0;
}
