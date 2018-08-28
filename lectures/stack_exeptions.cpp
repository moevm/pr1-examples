#include<iostream>
class StackEx: public std::exception{
public:

const char* what(){
	return "Stack exeption!!";	
}

};

class StackEmptyEx: public StackEx{
public:
const char* what(){
    return "Stack empty exeption!!";
}
};
using std::cout; using std::endl;

class Stack{
	int *arr;
	int n;
	int capacity;

public:
	Stack(int c){
		std::cout<<"Stack"<<endl;
		capacity = c;
		arr = new int[capacity];
		n = -1;
	}

	bool pop(int &val){
		if(isEmpty()){
			return false;
		}
		val = arr[n];
		n--;
		return true;
	}
	
	bool push(int a){
		if(n==capacity-1)
			return false;
		n++;
		arr[n] = a;
		return true;
	}

	int top(){
		if(isEmpty())
			throw StackEmptyEx();
		return arr[n];
	}

	bool isEmpty(){
		return n == -1;
	}

	~Stack(){
		std::cout<<"~Stack"<<endl;
		delete[] arr;
	}
};


Stack stackCreator(){

	Stack s(10);
	return s;

}

int main(){
	Stack s(10);
	s.
	try{	
	s.top();
	}
	catch(StackEmptyEx e){
		cout<<e.what();
	}
	 catch(StackEx e){
		cout<<e.what();
	}
	catch(std::exception e){
		cout<<e.what()<<std::endl;
	}
//	s = stackCreator();
	s.push(10);
	s.push(20);
	int res;
	while(s.pop(res)){
		cout<<"res = "<<res<<endl;
		}
		
	
	
	return 0;
}
