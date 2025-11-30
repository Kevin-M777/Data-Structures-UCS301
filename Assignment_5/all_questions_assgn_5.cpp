#include<iostream>

//Please Note that this single .cpp source file includes solutions to all the questions in Assignment 5 of Singly Linked Lists

class Node{
    public:
    int data;
    Node *next;
    Node(){data=0;next=NULL;}
    Node(int data){this->data=data;next=NULL;}
};

class LinkedList{
    Node *head;//we keep the head pointer secure by defining it in private scope
    public:
    LinkedList(){head=NULL;}
    Node *get_head(){return head;}
    void insert_beg(int data);
    void insert_end(int data);
    void insert_after_val(int val,int data);
    void insert_at_pos(int pos,int data);
    void delete_beg();
    void delete_end();
    void delete_by_val(int val);
    void display();
    int search(int num); //searches for element and also displays position at which elemnt was found
    friend void find_mid_el(LinkedList &test1);
    friend void del_all_inst_of_el(LinkedList &test1,int val);
};

void LinkedList::insert_beg(int data){
    Node *newnode= new Node(data);
    newnode->next=head;
    head=newnode;
    return;
}

void LinkedList::insert_end(int data){
    Node *newnode= new Node(data);
    Node *temp=head;
    if(temp==NULL){//if LL is empty
        head=newnode;
    }
    else{
        while(temp->next!=NULL) temp=temp->next;//if you do while(temp->next!=NULL) then you will exit before the last node
        //but if you do while(temp!=NULL) you will exit after the last node
        //in this case doing temp->next!=NULL is best.
        temp->next=newnode;
    }
    return;
}

void LinkedList::display(){
    Node *temp=head;
    if(temp==NULL)std::cout<<"LL is Empty!"<<std::endl;
    else{
        while(temp!=NULL){std::cout<<temp->data<<" ";temp=temp->next;}
        //since we did temp!=NULL we wont need to separately display the last node's data outside the loop as the last node is included in loop
        //if we did temp->next!=NULL, then we would need to do so as the last node wouldnt be included in the loop
        std::cout<<std::endl;
    }
    return;
}

int LinkedList::search(int num){
    Node *temp=head;int flag=0;int pos=1; //also calculates position at which element was found
    if(temp==NULL){std::cout<<"LL is Empty, cannot search!"<<std::endl;return -1;}
    else{
        while(temp!=NULL){//will search through even the last node's element
            if(temp->data==num){flag=1;break;}
            temp=temp->next;pos++;
        }
        if(flag==1){std::cout<<"Element Exists! and found at pos:"<<pos<<std::endl;return num;}
        else {std::cout<<"Element does not Exist!"<<std::endl;return -1;}
    }
}

void LinkedList::insert_after_val(int val,int data){
    Node *newnode= new Node(data);
    Node *temp=head;
    if(temp==NULL) head=newnode;
    else{
        //Note in the below while condition its very important that the condition temp!=NULL comes first, if it came second then in the case
        //where val does not exist, after you cover all nodes and temp=NULL then before checking temp!=NULL it will try to dereference the
        //NULL pointer which leads to silent crash or undefined behaviour of the program.
        //Thus it must be while(temp!=NULL&&temp->data!=val) and NOT  while(temp->data!=val&&temp!=NULL)
        while(temp!=NULL&&temp->data!=val){temp=temp->next;} //remember to also handle the case if val is not found
        //ie when you reached the end of the LL (temp=NULL) and still never met the condition temp->data==val
        //the above loop will exit if we either traversed through all nodes without getting val or if we got val
        //in one of the nodes
        if(temp==NULL) std::cout<<"Value does not exist"<<std::endl;
        else{
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
    return;
}

void LinkedList::insert_at_pos(int pos,int data){
    if(pos<0){std::cout<<"Invalid Position!"<<std::endl;return;}
    Node *temp=head;int i;
    for(i=1;i<pos-1;i++){
        temp=temp->next;
        //in this loop we go from i=1 to <pos-1 instead of <pos (ie we go one step less). See this is because before even entering the loop
        //we are already at the first node, so in the 1st iteration of the loop we go to the 2nd node and so on ie we are already +1 ahead.
    }
    Node *newnode= new Node(data);
    if(pos==1){newnode->next=head;head=newnode;return;}
    //Note: This insert_at_pos() function wont work correctly if pos=1 as there it will insert the element at the second pos instead of first.
    //So we ensure that if pos=1 it inserts at the 1st pos.
    newnode->next=temp->next;
    temp->next=newnode;
    return;
}

void LinkedList::delete_beg(){
    if(head==NULL){std::cout<<"LL is Empty!"<<std::endl;return;}
    Node *temp=head;//store the 1st node's address in a temp variable so that you can free up the memory allocated to it after making the 2nd
    //node into the 1st node
    head=head->next;//this also handles the case where there is only one element in the LL
    delete temp;//free up the memory allocated to the original 1st node
    return;
}

void LinkedList::delete_end(){
    //note we could implement this function using the two pointer method too
    if(head==NULL){std::cout<<"LL is Empty!"<<std::endl;return;}
    Node *temp=head;
    if(temp->next==NULL){head=NULL;delete temp;return;} //handles the case where there is only one element in LL
    while(temp->next->next!=NULL) temp=temp->next;
    Node *buff=temp->next;
    temp->next=NULL;
    delete buff;
    return;
}

void LinkedList::delete_by_val(int val){
    if(head==NULL){std::cout<<"LL is Empty!"<<std::endl;return;}
    Node *temp=head;
    Node *prev=NULL;
    while(temp!=NULL&&temp->data!=val){prev=temp;temp=temp->next;}
    if(temp==NULL) std::cout<<"Value does not exist!"<<std::endl;
    else if(temp==head){head=temp->next;}//handles two cases 1) when the value to be deleted lies in the 1st node 2)if there is only one node
    //and that node contains the value
    else{
        prev->next=temp->next;
    }
    delete temp;
    return;
}

void reverse(Node *temp){//display elements of LL in reverse order using recursion
    if(temp->next==NULL){std::cout<<temp->data<<" ";return;}
    else{
        reverse(temp->next);
        std::cout<<temp->data<<" ";
        return;
    }
}

void del_all_inst_of_el(LinkedList &test1,int val)
{
    //find the number of instances of the element
    Node *temp=test1.head; int count=0;int i;
    if(temp==NULL)std::cout<<"LL is Empty!"<<std::endl;
    else{
        while(temp!=NULL)
        {
            if(temp->data == val)count++;
            temp=temp->next;
        }
        for(i=0;i<count;i++) test1.delete_by_val(val); //delete all instances
    }
}

int main(){
    LinkedList test1;
    test1.insert_beg(1);test1.insert_end(24);test1.insert_end(17);test1.insert_end(24);test1.insert_end(24);
   
    del_all_inst_of_el(test1,24);
    test1.display();
    return 0;
}