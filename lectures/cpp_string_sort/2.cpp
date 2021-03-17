#include <iostream>

struct S{
	int a;
	std::string *s;
};

int cmp(const void *a, const void *b){
	S *aa = (S*) a;
	S *bb = (S*) b;
	return aa->s->compare(*(bb->s));
}

int main(){
	struct S arr[] = {{10, new std::string("qwer")}, {23, new std::string("asdadf")}, {5553, new std::string("dsdfsa")}};
	const int n = sizeof(arr)/sizeof(S);
	for(int i=0; i<n; i++)
		std::cout<<arr[i].a<<" "<<*arr[i].s<<std::endl;
	qsort(arr, n, sizeof(S), cmp);
	for(int i=0; i<n; i++)
		std::cout<<arr[i].a<<" "<<*arr[i].s<<std::endl;

	return 0;

}
