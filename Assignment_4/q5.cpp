#include<iostream>
//Implementing stacks using one and 2 queues
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

void push(queue &test, int data){ //using single Q
	test.enqueue(data);
	int temp;
	while(test.peek()!=data){//O(n)
		temp=test.dequeue();
		test.enqueue(temp);
	}
}

int pop(queue &test){ //using single Q
	return test.dequeue();
}

void push2(queue &test1,queue &test2,int data){//using 2 q
    test2.enqueue(data);
    while(!test1.isEmpty()){test2.enqueue(test1.dequeue());}

    queue temp = test1;
    test1 = test2;
    test2 = temp;
}

int pop2(queue &test1){//using 2 q
    if(test1.isEmpty()){std::cout<<"Undeflow"<<std::endl;return -1;}
    else return test1.dequeue();
}

int main(){
    queue q1(5),q2(5);
    push2(q1,q2,1);
    push2(q1,q2,2);
    push2(q1,q2,3);
    push2(q1,q2,4);
    push2(q1,q2,5);
    std::cout<<pop(q1); //output will be 5

    return 0;
}