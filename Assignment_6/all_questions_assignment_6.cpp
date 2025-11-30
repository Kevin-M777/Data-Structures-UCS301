#include<iostream>

//Have tried to cover all questions of Assignment 6 into this single .cpp source file.

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
    void insert_at_beg(int data);
    void insert_at_end(int data);
    void insert_after_val(int val,int data);
    void delete_from_beg();
    void delete_from_end();
    void delete_at_val(int val);
    void search(int val);
    int find_size();
    void display();
    int cll_check(); //checks if this is a circular linked list or not
};

void LinkedList::insert_at_beg(int data){
    Node *newnode= new Node(data);
    if(head==NULL){head=newnode;newnode->next=head;return;}//The order in which you write the statements for the pointers are very important!
    else{
        Node *temp=head;
        while(temp->next!=head)temp=temp->next; //finding the apparent last node
        newnode->next=head;
        temp->next=newnode;
        head=newnode;
    }
    return;
}

void LinkedList::insert_at_end(int data){
    Node *newnode= new Node(data);
    if(head==NULL){head=newnode;newnode->next=head;return;}
    Node *temp=head;
    while(temp->next!=head)temp=temp->next;
    temp->next=newnode;
    newnode->next=head;
    return;
}

void LinkedList::search(int val){
    if(head==NULL){std::cout<<"LL is Empty!"<<std::endl;return;}
    Node *temp=head;
    while(temp->next!=head&&temp->data!=val) temp=temp->next;//since we are doing temp->next!=head, we will miss checking if the last node
    //of the LL has the value or not.  So in the if-else block first check if the last node has the val or not.
    if(temp->data==val)std::cout<<"Value found!"<<std::endl;//checking last node, works even if val was found in any middle node
    else std::cout<<"Value not found!"<<std::endl;
    //note we cant do temp!=head as then we will never enter the while loop only, this is an imp point in Circular LL
    return;
}

void LinkedList::display(){
    if(head==NULL){std::cout<<"LL is Empty!"<<std::endl;return;}
    Node *temp=head;
    while(temp->next!=head){std::cout<<temp->data<<" ";temp=temp->next;}
    std::cout<<temp->data<<" "<<temp->next->data<<std::endl; //to ensure that in the display circularity is shown, have displayed head at end too
    return;
}

void LinkedList::insert_after_val(int val,int data){
    if(head==NULL){std::cout<<"LL is Empty"<<std::endl;return;}
    Node *newnode= new Node(data);
    Node *temp=head;
    while(temp->next!=head&&temp->data!=val)temp=temp->next;
    if(temp->data==val){newnode->next=temp->next;temp->next=newnode;}//this approach is quite efficient
    else std::cout<<"Inputted val does not exist!"<<std::endl;
    return;
}

void LinkedList::delete_from_beg(){
    if(head==NULL){std::cout<<"LL is empty!"<<std::endl;return;}
    Node *temp=head;//this address must be freed later on
    if(temp->next==head){head=NULL;} //handles the case where there is only one node, this case is quite common for Circular LL
    else{
        while(temp->next!=head)temp=temp->next;
        head=head->next;
        temp->next=head;
    } 
    delete temp;
    return;
}

void LinkedList::delete_from_end(){//efficient, method given in ppt
    if(head==NULL){std::cout<<"LL is empty!"<<std::endl;return;}
    Node *temp=head;Node *prev=NULL;
    while(temp->next!=head){prev=temp;temp=temp->next;}
    if(temp==head)head=NULL;
    else prev->next=head;
    delete temp;
    return;
}

void LinkedList::delete_at_val(int val){
    if(head==NULL){std::cout<<"LL is empty!"<<std::endl;return;}
    Node *temp=head;Node *prev=NULL;
    while(temp->next!=head&&temp->data!=val){prev=temp;temp=temp->next;}
    if(temp->data!=val)std::cout<<"VAl not found"<<std::endl; //if even the last node does not have it then that val doesnt exist
    else if(temp==head){
        if(temp->next==head)head=NULL;//handles the case where there is only one node in the LL
        else{//esentially implementing the delete_from_beg() function here
            Node *buf=temp;
            while(buf->next!=head)buf=buf->next;
            head=head->next;
            buf->next=head; 
            //Note: If we used temp here instead of buf then by the end of the else block , temp would point to the last node, then 
            //when we delete temp we will actually delete the last node which will cause errors in the display function like
            //printing infinite addresse or garbage! So instead i used another variable so that temp remained the address of the head node
            //ie the node we wanted to delete in this case.
        }   
    }
    else prev->next=temp->next;
    delete temp;
    return;
}

int LinkedList::find_size(){
    if(head==NULL){std::cout<<"LL is Empty"<<std::endl;return 0;}
    Node *temp=head;int size=1;
    while(temp->next!=head){temp=temp->next;size++;}
    return size;
}

int LinkedList::cll_check(){ //done in hurry, not the best approach, havent thought much
    if(head==NULL){std::cout<<"LL is Empty"<<std::endl;}
    Node *temp=head;int flag=0;
    while(temp!=NULL)
    {
        if(temp->next==head){flag=1;break;} //cycle found ie found a node pointing back to head
        temp=temp->next;
    }
    if(flag==1)return 1; //LL is Circular
    else return 0; //LL is not Circular
}

int main(){
    LinkedList test;
    test.insert_at_beg(1);
    test.insert_at_end(2);test.insert_at_end(3); //1 2 3
    test.insert_after_val(3,4); //1 2 3 4
    test.display();
    
    std::cout<<test.cll_check();
    
    return 0;
}