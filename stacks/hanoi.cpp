#include <iostream>

class Stack {
public:
	int pos;
	int capacity = 0;
	int *values ;
	Stack(){
		this->capacity = 1;
		this->values = new int[this->capacity];
		for(int i=0;i<this->capacity;i++){
			this->values[i] = 0;
		}
		this->pos = 0;
	}
	int pop(){
		if(this->pos == 0){
			std::cout <<"Stack Underflow"<< std::endl; 
			return -1;
		}
		int r = this->values[this->pos];
		std::cout<<"Getting position: "<<this->pos<<" with the value "<< r<< std::endl;
		
		this->pos--;
		return r;
	}	
	void push(int x){
		
		if(this->pos >= 64000){
			std::cout <<"Stack Overflow"<< std::endl; 
		}
		std::cout<<"Setting position: "<<this->pos<<" to the value "<< x<< std::endl;
		this->pos++;
		if(this->pos > this->capacity){ // we have exceeded capacity, time to double the capacity
			int* temp = new int[this->capacity * 2];
			for(int i=0;i<this->pos;i++){
				temp[i] = this->values[i];
			}
			this->values = temp;
			this->capacity *= 2;
		}
		this->values[this->pos] = x;
	}
};
int main(int argc, char** argv){
	Stack s;
	for(int i=0;i<10000;i++){
		//for(int j=0;j<10000;j++){
		//	s.push(11231);
			s.push(11231);
		//}
	}
	s.push(11232);
	s.push(11233);
	s.push(11234);
	std::cout << s.pop() << std::endl;
	std::cout << s.pop() << std::endl;
	std::cout << s.pop() << std::endl;
	std::cout << s.pop() << std::endl;
	std::cout << s.pop() << std::endl;
	std::cout << s.pop() << std::endl;
	return 0;
}
