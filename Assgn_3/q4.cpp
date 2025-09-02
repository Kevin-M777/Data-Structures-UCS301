#include<iostream>
#include<string>
//Program to convert infix to postfix 
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
};

int is_operator(std::string op){
	if (op=="+"||op=="-"||op=="/"||op=="*"||op=="%") return 1;
	return 0;
}

int in_check(std::string A[],int size,std::string op){
	int i,flag=0;
	for(i=0;i<size;i++) if (A[i]==op){flag=1;break;}
	if(flag==1)return 1;
	else return 0;
	
}

int precedence(std::string op1, std::string op2)
{
	std::string A1[]={"+","-"};
	std::string A2[]={"*","/","%"};
	//0 means op1 is higher, 1 means op2 is higher and 2 means both operators are of equal precedence
	if(in_check(A1,2,op1)&&in_check(A2,3,op2)) return 1;
	else if (in_check(A1,2,op2)&&in_check(A2,3,op1)) return 0;
	else return 2;
}

int main(){
    Stack test;
	std::string str;
	std::cout<<"Enter infix exression:";
	std::getline(std::cin,str);
	str=str+" )";int i;
	test.push("(");
	std::string postfix;

	std::string temp="";
     
	for(i=2;i<str.length();i++){
		int j=i;
		temp=temp+str[j];
		//handle multi digit numbers and differentiate them from single digit numbers using spaces
		while(j!=str.length()-1&&str[j+1]!=' '){
			temp=temp+str[j+1];//str[j+1] is implicitly converted from char to string
			j++;
		}
		i=j+1;//for loop does + 1 more increment so do i=j+1 instead of i=j+2
		//temp is a string holding the current character
	
		if (is_operator(temp)){
			if(test.isEmpty()) test.push("(");
			while(is_operator(test.peek())==1){
				std::string p=test.peek();
				if(precedence(temp,p)==2||precedence(temp,p)==1){;
					std::string e=test.pop();
					postfix=postfix+e+" ";
				}
				else break;
			}
			test.push(temp);	
		}
		else if (temp=="(") test.push(temp);
		else if (temp==")"&&!(test.isEmpty())) {
			while(test.peek()!="(" && !test.isEmpty()){
				std::string p=test.pop();
				postfix=postfix+p+" ";
			}
			test.pop();//remove the remaining left parenthesis
			
		}
		else{
			if(!(test.isEmpty())) postfix=postfix+temp+" ";
			//specified above condition to handle the last right parenthesis we inserted at the beginning
			//else that right parenthesis will get included in the postfix expression
		}
		temp="";
	}
	std::cout<<postfix<<std::endl;
	return 0;
}


