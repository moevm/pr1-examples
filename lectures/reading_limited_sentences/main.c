#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/*
 * Задание: реализовать программу, которая будет считывать массив строк. Количество строк заранее неизвестно. Длина строк не более 1000 символов.
 * Далее программа должна отсортировать в алфавитном порядке без учета регистра каждое слово в строке и вывести на экран.
 */

#define MAX_STR_SIZE 1001
#define DEFAULT_SIZE 5
#define REALLOC_STEP DEFAULT_SIZE

int compar(const void *a, const void *b) {
	char *char_a = (char *)a;
	char *char_b = (char *)b;
	return tolower(*char_a) - tolower(*char_b); // Сравниваем символы без учета регистра
}

void process_word(char *word, int count) {
	//qsort(word, count, sizeof(char), compar); // Сортируем символы в слове
	// Или сортировка пузырьком:
	for (int i = 0; i < count; i++) {
		for (int j = 1; j < count; j++) {
			if (tolower(word[j]) < tolower(word[j-1])) {
				char tmp = word[j];
				word[j] = word[j-1];
				word[j-1] = tmp;
			}
		}
	}
}

void process_sent(char *sent) {
	int i;
	int start = -1;
	int end = -1;
	int is_word = 0;
	for (i = 0; sent[i] != '\n' && sent[i] != '\0'; i++) { // Итерируем посимвольно для поиска пробелов
		if (!isspace(sent[i]) && is_word == 0) { // Если мы встретили символ отличный от пробленого, то это начало слова
			start = i; // Сохраняем индекс начала слова
			is_word = 1; // выставляем флаг, что слово началось
		}
		if (isspace(sent[i]) && is_word == 1) { // Если встретили пробел, при этом мы в процессе поиска конца слова
			end = i; // Сохраняем индекс конца слова
			is_word = 0; // Переходим опять к поиску нового слова
			process_word(&sent[start], end - start); // Сортируем символы в слове
		}
	}
	if (is_word == 1) { // Исключительная ситуация: если в конце предложения нет пробела, то необходимо такое слово тоже обработать
		end = i;
		process_word(&sent[start], end - start);
	}
}

void process_text(char **text, int count) {
	for (int i = 0; i < count; i++) { // Пробегаемся по предложениям
		process_sent(text[i]); // Обрабатываем отдельное предложение
	}
}

int read_text(char ***text) {
	int i = 0;
	int cur_size = DEFAULT_SIZE;
	while(fgets((*text)[i], MAX_STR_SIZE, stdin)) { // Bad practice: while(scanf("%s", (*text)[i]) == 1)
	       i++;
	       if (cur_size == i) { // Если в text нет места под следующее предложение
		       int new_size = cur_size + REALLOC_STEP; // Вычисляем новый размер text прибавляя шаг
		       char **new_arr = realloc(*text, new_size * sizeof(char **)); 
		       if (new_arr == NULL) {
			       printf("Error occured during memory reallocing!");
			       break;
		       }
		       *text = new_arr;
		       for (;cur_size < new_size; cur_size++) {
			       (*text)[cur_size] = calloc(MAX_STR_SIZE, sizeof(char)); // Довыделяем память под каждое новое предложение
		       }
	       }
	}
	return i;
}

int main(){
	// char * == char []
	// char ** == char [][]
	char **text = malloc(sizeof(char *) * DEFAULT_SIZE); // Выделяем память под массив предложений
	for (int i = 0; i < DEFAULT_SIZE; i++) // Обходим выделенный массив для выделения памяти под каждое предложение (строки)
		text[i] = calloc(MAX_STR_SIZE, sizeof(char)); // Выделение памяти под строку
	int count = read_text(&text); // Функция считывания текста из stdin
	printf("Sentence count: %d\n", count);
	process_text(text, count); // Сортируем слова
	for (int i = 0; i < count; i++) { // Печатаем результат
		printf("%s", text[i]);
		free(text[i]);
	}
	free(text);

	return 0; 

}
