#include<iostream>
#include<string>
//Menu Drive program for stack
//have used 0 to represent underflow and overflow cases
#define MAXLEN 20

class Stack{
	int s[MAXLEN];
	int top=-1;
	public:
        bool isEmpty(){
			return (top==-1);
		}
		bool isFull(){
			return (top==MAXLEN-1);
		}
		void push(int x){
			if(isFull()) std::cout<<"Stack overflow alert\n";
			else{
				top++;
				s[top]=x;
			}
		}
	    int pop(){
			if(isEmpty()) std::cout<<"Stack Underflow Alert from pop!\n";
			else{ 
				return s[top--];	
			}
			return 0; //refers to underflow case
		}
		int peek(){
			if (isEmpty()) std::cout<<"Stack Underflow Alert from peek!\n";
			else return s[top];
			return 0;
		}
		void display(){
			int i;
			for(i=top;i>=0;i--){
				std::cout<<s[i]<<" ";
			}
			std::cout<<"\n";
		}
};


int main(){
    Stack test;int e;
	int opt=1000;

	while (opt!=7){
		std::cout<<"1.push 2.pop 3.isEmpty 4.isFull 5.display 6.peek 7.EXIT"<<std::endl;
		std::cout<<"Enter Menu option:"<<std::endl;
		std::cin>>opt;
		if (opt==1){
			std::cout<<"Enter element for pushing:";
			std::cin>>e;
			test.push(e);
		}
		else if (opt==2){
			e=test.pop();
			if(e!=0) std::cout<<"Popped Element is:"<<e<<std::endl;
		}
		else if (opt==3){
			if(test.isEmpty()) std::cout<<"Stack is empty"<<std::endl;
			else std::cout<<"Stack not empty"<<std::endl;
		}
		else if (opt==4){
			if(test.isFull()) std::cout<<"Stack is full"<<std::endl;
			else std::cout<<"Stack is not full"<<std::endl;
		}
		else if (opt==5){
			std::cout<<"The contents of the stack are:";
			test.display();
		}
		else if (opt==6){
			std::cout<<"The top element is:"<<test.peek()<<std::endl;
		}
		else if(opt==7){
			std::cout<<"EXITED"<<std::endl; 
		}
		else std::cout<<"Invalid Option"<<std::endl;
	}

	return 0;
}




