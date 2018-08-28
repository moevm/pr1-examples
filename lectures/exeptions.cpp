#include <iostream>
//#include <exeption>

int f(int n) {
	if(n > 1)
		throw 777;
	if(n<0)
		throw 45;
	return 0;
}

int main(){
try{
	try{
		std::cout<<"[";
		f(-10);
		std::cout<<"]";
	} catch(int e){
		std::cout<<"catched: "<<e<<std::endl;
		throw;
	} catch(int e){
		std::cout<<e;
	}
}
 catch(...){
	std::cout<<"any";
}

return 0;
}
