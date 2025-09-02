#include<iostream>
#include<string>
//progam for postfix evaluation
//have taken "0" (string) to represent extreme cases
#define MAXLEN 20

class Stack{
	std::string s[MAXLEN];
	int top=-1;
	public:
        bool isEmpty(){
			return (top==-1);
		}
		bool isFull(){
			return (top==MAXLEN-1);
		}
		void push(std::string x){
			if(isFull()) std::cout<<"Stack overflow alert\n";
			else{
				top++;
				s[top]=x;
			}
		}
	    std::string pop(){
			if(isEmpty()) std::cout<<"Stack Underflow Alert from pop!\n";
			else{ 
				return s[top--];	
			}
			return "0"; //refers to underflow case
		}
		std::string peek(){
			if (isEmpty()) std::cout<<"Stack Underflow Alert from peek!\n";
			else return s[top];
			return "0";
		}
		int top_index(){
			return top;
		}
};

int is_operator(std::string op){
	if (op=="+"||op=="-"||op=="/"||op=="*"||op=="%") return 1;
	return 0;
}

int operate(std::string op,int x,int y){
	if (op=="+") return x+y;
	else if (op=="-") return x-y;
	else if (op=="/") return x/y;
	else if (op=="*") return x*y;
	else return x%y;
}

int main(){
    Stack test;
	std::string str;
	std::cout<<"Enter postfix exression:";
	std::getline(std::cin,str);
	std::string infix;int i;
	int a,b,res,final;
	std::string temp="";
     
	for(i=0;i<str.length();i++){
		int j=i;
		//handle multi digit numbers and differentiate them from single digit numbers using spaces
		temp=temp+str[j];
		while(j!=str.length()-1&&str[j+1]!=' '){
			temp=temp+str[j+1];//str[j+1] is implicitly converted from char to string
			j++;
		}
		i=j+1;//for loop does + 1 more increment so do i=j+1 instead of i=j+2
		//temp is a string holding the current character
	
		if (is_operator(temp)){
			int ti= test.top_index();
			if (ti>=1){
				//ensuring we have atleast 2 operands in the stack to operate on
				b=std::stoi(test.pop()); //remeber that the second popped element comes first in the operation
				a=std::stoi(test.pop());
				res=operate(temp,a,b);
				test.push(std::to_string(res));
				
			}
			else {
				std::cout<<"ERROR not enough elements!"<<std::endl;
				break;
			}
		}
		else{
			test.push(temp);
		}
		
		temp="";
	}
	final =std::stoi(test.pop());//the ending case, its very important that it comes outside the main loop
	std::cout<<"Final evaluated result: "<<final<<std::endl;

	return 0;
}




