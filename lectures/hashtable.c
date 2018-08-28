#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define K 101
// 8 bit
unsigned char hash(char *arr, int n){
	unsigned char res = 0;
	for(int i=0; i<n; i++){
		res = (res + arr[i]) % K;
	}
	return res;
}
struct pair{
	int key;
	int val;
};

struct hashtable{
	struct pair *arr[K];	
};

void init(struct hashtable *table){
	for(int i=0; i<K; i++){
		table->arr[i] = NULL;
	}
}

void add(struct hashtable *table, int key, int val){
	unsigned char h = hash((char*)&key, sizeof(key));
	struct pair *p = malloc(sizeof(struct pair));
	p->key = key;
	p->val = val;
	table->arr[h] = p;
}

int contains(struct hashtable *table, int key){
	unsigned char h = hash((char*)&key, sizeof(key));
	if(table->arr[h] == NULL){
		return 0;
	}else{
		return table->arr[h]->key == key;
	}
}

void rem(struct hashtable *table, int key){
	unsigned char h = hash((char*)&key, sizeof(key));
	free(table->arr[h]);
	table->arr[h] = NULL;
}

int get(struct hashtable *table, int key){
	unsigned char h = hash((char*)&key, sizeof(key));
	if(table->arr[h])
		return table->arr[h]->val;	
	return 0;
}

int main(){
	char s[10];
	struct hashtable table;
	init(&table);
	add(&table, 2, 4);
	add(&table, 3, 9);
	add(&table, 4, 16);
	add(&table, 5, 25);
	for(int i=0; i<10; i++){
		printf("%d: %d\n", i, contains(&table, i));
		if(contains(&table, i)){
			printf("[%d]\n", get(&table, i));
		}
	}
	return 0;
}
