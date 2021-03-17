#include <iostream>
#include <vector>
#include <algorithm>

struct S{
	int a;
	std::string s;
};

bool cmp(S a, S b){
	return a.s<b.s;
}

int main(){
	std::vector<S> v = {{10, "qwer"}, {23, "asdadf"}, {5553, "dsdfsa"}};
	for(S &elem: v)
		std::cout<<elem.a<<" "<<elem.s<<std::endl;
	std::sort(v.begin(), v.end(), cmp);	
	for(S &elem: v)
		std::cout<<elem.a<<" "<<elem.s<<std::endl;

	return 0;

}
