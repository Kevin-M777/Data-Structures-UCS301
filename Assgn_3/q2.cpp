#include<iostream>
#include<string>
//Program to reverse a string using stack
//Have used '*' for underflow and overflow cases
#define MAXLEN 20

class Stack{
	char s[MAXLEN];
	int top=-1;
	public:
        bool isEmpty(){
			return (top==-1);
		}
		bool isFull(){
			return (top==MAXLEN-1);
		}
	    char peek(){
			if(isEmpty()) std::cout<<"Stack is empty!!\n";
			else return s[top];
			return '*';//here return X means empty stack
		}
		void push(char x){
			if(isFull()) std::cout<<"Stack Overflow!\n";
			else{
				top++;
				s[top]=x;
			}
		}
		char pop(){
			if(isEmpty()) std::cout<<"Stack Underflow!\n";
			else{ 
				return s[top--];	
			}
			return '*'; //refers to underflow case
		}
		void display(){
			int i;
			for(i=top;i>=0;i--){
				std::cout<<s[i]<<" ";
			std::cout<<"\n";
			}
		}
};

int main(){
    Stack test;
	std::string str;
	std::cout<<"Enter your string:";
	std::getline(std::cin,str); 
	int i;int flag=0;
    for(i=0;i<str.length();i++){
        test.push(str[i]);
    }
    //display the reversed string
    for(i=0;i<str.length();i++){
        std::cout<<test.pop();
    }
	return 0;
}




