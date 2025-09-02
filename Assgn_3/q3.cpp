#include<iostream>
#include<string>
//Program to check for balanced parenthesis using stack
//have assumed that X will never be an element of the stack
#define MAXLEN 5
char convert(char b){
	if(b=='[') return ']';
	if(b=='{') return '}';
	if(b=='(') return ')';
}
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
			return 'X';//here return X means empty stack
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
			return 'X'; //refers to underflow case
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
	std::cout<<"Enter Parenthesis Order:";
	std::cin>>str;
	int i;int flag=0;
	for(i=0;i<str.length();i++){
		if(str[i]=='{'||str[i]=='('||str[i]=='[') test.push(str[i]);
		else if (str[i]=='}'||str[i]==')'||str[i]==']'){
			char a=test.pop();
			if(a=='X'){flag=1;break;}//handles case where we have extra closing bracket
			if(str[i]!=convert(a)){ flag=1;break;}
		}
		else {std::cout<<"Invalid Parenthesis string"<<std::endl;flag=2;break;}
	}
	if(!(test.isEmpty())) flag=1; //handles case with extra opening bracket
	if(flag==1) std::cout<<"Imbalanced Parenthesis"<<std::endl;
	if(flag==0) std::cout<<"Balanced Parenthesis"<<std::endl;
	// std::cout<<convert('(')<<std::endl;
	
	return 0;
}




