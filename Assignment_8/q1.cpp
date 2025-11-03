#include<iostream>
#define MAXLEN 4
//Menu driven program for simple Q, have tried to handle all types of extreme cases
//Have used 0 to represent extreme cases
class queue{
    int test[MAXLEN];
    int front=-1;int rear=-1;
    public:
    bool isEmpty(){
        return((front==-1&&rear==-1)||(front>rear));//handles both the standard case as well as the flawed case
    }
    bool isFull(){
        return(rear==MAXLEN-1&&front==0);
    }
    void enqueue(int x){
        if(isFull()) std::cout<<"Overflow error!"<<std::endl;//in the flaw case of Q this condition wont be satisfied
        //hence we apply a front>rear condition in else block to ensure it realises that no more space is available
        //despite isFull() returning False
        else{
            if(front>rear)std::cout<<"Q is stuck, its full yet empty, major flaw of simple Q"<<std::endl;
            else{
            if(front==-1&&rear==-1) front=0;//handles updation of front for insertion of first element
            rear++;
            test[rear]=x;
            }
        }
        return;
    }
    int dequeue(){
        if(isEmpty()) std::cout<<"Underflow Error!"<<std::endl;
        else{
            int x=test[front++];
            return x;
        }
        return 0;
    }
    int peek(){
        if(isEmpty())std::cout<<"Q Underflow Error"<<std::endl;
        else return test[front];
        return 0;
    }
    void display(){
        if(!isEmpty()){
        int i;
        for(i=front;i<=rear;i++){
            std::cout<<test[i]<<" ";
        }
        std::cout<<std::endl;
        }
        else std::cout<<"No elements to display"<<std::endl;
        return;
    }
    int f(){return front;}
    int r(){return rear;}
};

int main(){
    queue demo;
    int ch=100;
    while(ch!=7){
        std::cout<<"Enter choice:";
        std::cin>>ch;
        if(ch==1){
            if(demo.isEmpty())std::cout<<"Q is Empty"<<std::endl;
            else std::cout<<"Q not empty"<<std::endl;
        }
        else if(ch==2){
            if(demo.isFull())std::cout<<"Q is Full"<<std::endl;
            else std::cout<<"Q not full"<<std::endl;
        }
        else if(ch==3){
            int num;
            std::cout<<"Enter element:";
            std::cin>>num;
            demo.enqueue(num);
        }
        else if(ch==4){
            int num=demo.dequeue();
            if(num!=0) std::cout<<"Dequeued element:"<<num<<std::endl;
        }
        else if(ch==5){
            int num=demo.peek();
            if(num!=0) std::cout<<"Front element:"<<num<<std::endl;
        }
        else if(ch==6) demo.display();
        else if(ch==7) std::cout<<"EXITED";
        else std::cout<<"Invalid option"<<std::endl;
    }
    return 0;
}