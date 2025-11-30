#include<iostream>
//Interleaving using Queues Question
class queue{
    int front;int rear;
    int max;
    int *q;
    public:
    queue(int max){front=-1;rear=-1;this->max=max;q=(int*)malloc(max*sizeof(int));}
    bool isFull();
    bool isEmpty();
    void enqueue(int data);
    int dequeue();
    void display();
    int peek(){return q[front];}
    void interleave();
};

bool queue::isFull(){
    if(front==(rear+1)%max) return true;
    else return false;
}

bool queue::isEmpty(){
    return (front==-1);
}

void queue::enqueue(int data){
    if(isFull())std::cout<<"OVERFLOW"<<std::endl;
    else{
        rear=(rear+1)%max;
        q[rear]=data;
        if(front==-1)front=0; //if this was the first enqueue then we need to update front too!
    }
}

int queue::dequeue(){
    if(isEmpty())std::cout<<"UNDERFLOW"<<std::endl;
    else{
        int num=q[front];
        if(front==rear){front=-1;rear=-1;}
        else front=(front+1)%max; 
        return num;
    }
    return -1; //-1 for underflow case  
}

void queue::display(){
    int i;
    for(i=front;i!=rear;i=(i+1)%max){
        std::cout<<q[i]<<" ";
    }
    std::cout<<q[rear]<<std::endl;
    return;
}

void queue::interleave(){
    int i;int half_len = max/2;
    queue temp(half_len);
    for(i=0;i<half_len;i++){temp.enqueue(dequeue());}
    for(i=0;i<half_len;i++){enqueue(temp.dequeue());enqueue(dequeue());}
    display();
}

int main(){
    queue test(6);
    test.enqueue(4);
    test.enqueue(7);
    test.enqueue(11);
    test.enqueue(20);
    test.enqueue(5);
    test.enqueue(9);

    test.interleave();
    
    return 0;
}