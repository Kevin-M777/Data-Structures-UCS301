#include<iostream>
//Implementing Dijkstras Shortest Path Algorithm without STL
/*
Notes:
Have taken undirected graph for this implementation.
Most efficient way to implement Priority Q is using min Heap but have used Linked List here.
*/
class Node{
    public:
    int vertex;//represents vertex index
    int weight;
    Node *next;
    Node(int vertex, int weight){this->vertex=vertex;this->weight=weight;next=NULL;}
};

class LinkedList{
    Node *head;
    public:
    LinkedList(){head=NULL;}
    Node *get_head(){return head;}
    void insert_end(int v,int wt);
    void sorted_insert(int v,int wt);
    Node *delete_beg();
    void display();
};

class priorityq{
    public:
    LinkedList q; //Vertex with shortest distance to intial vertex must have highest priority
    void enqueue(int v,int wt){
        if(q.get_head()==NULL) q.insert_end(v,wt);
        else{//perform sorted insertion
                q.sorted_insert(v,wt);
        }
    }
    Node *dequeue(){
        Node *temp= q.delete_beg();
        return temp; //remember to free memory after usage in algorithm
    }
    void display(){
        q.display();
    }
    bool isEmpty(){return (q.get_head()==NULL);}
};

class graph{//used to create the adjaceny list of the graph
    public:
    int vertices;
    LinkedList *adj;
    graph(int v){vertices=v;adj=new LinkedList[v];}
    void add_edge(int u,int v,int w){ 
        //edge from node u to v with weight w
        (adj[u]).insert_end(v,w); //Note: as of now the connected vertices for each vertex have not been stored in ascending order
        (adj[v]).insert_end(u,w);
    }
    void display_graph(){
        int i;
        for(i=0;i<vertices;i++){std::cout<<"For vertex:"<<i<<std::endl;(adj[i]).display();}
    }
};

void LinkedList::insert_end(int v,int wt){
    Node *newnode= new Node(v,wt);
    Node *temp=head;
    if(temp==NULL){//if LL is empty
        head=newnode;
    }
    else{
        while(temp->next!=NULL) temp=temp->next;
        temp->next=newnode;
    }
    return;
}

void LinkedList::display(){
    Node *temp=head;
    if(temp==NULL)std::cout<<"LL is Empty!"<<std::endl;
    else{
        while(temp!=NULL){std::cout<<"Vertex:"<<temp->vertex<<" "<<"Weight:"<<temp->weight<<" | ";temp=temp->next;}
        std::cout<<std::endl;
    }
    return;
}

void LinkedList::sorted_insert(int v,int wt){
    Node *newnode= new Node(v,wt);
    if(head==NULL){head=newnode;return;}
    Node *prev=NULL,*temp=head;
    while(temp!=NULL&&temp->weight<newnode->weight){prev=temp;temp=temp->next;}
    if(temp==NULL){prev->next=newnode;}
    else{
        if(prev==NULL){newnode->next=head;head=newnode;}
        else{
            newnode->next=prev->next;//handles insertion anywhere in the middle
            prev->next=newnode;
        }
    }
    return;
}

Node *LinkedList::delete_beg(){
    if(head==NULL){std::cout<<"LL is Empty!"<<std::endl;return NULL;}
    Node *temp=head;//store the 1st node's address in a temp variable so that you can free up the memory allocated to it after making the 2nd
    //node into the 1st node
    head=head->next;//this also handles the case where there is only one element in the LL
    return temp;//will delete it later after extracting its info
}

int main(){
    int v=5;int src_vertex=0;//source vertex
    graph ob(v);//initializing the graph
    ob.add_edge(0,1,4);
    ob.add_edge(0,2,8);
    ob.add_edge(1,4,6);
    ob.add_edge(2,3,2);
    ob.add_edge(4,3,10);
    priorityq pq; int i;
    
    //Dijkstra's Algorithm
    int *distance=(int *)malloc(v*sizeof(int));//initialize distance array
    for(i=0;i<v;i++){
        distance[i]=1000000;
    }
    distance[src_vertex]=0;

    //have use 100000 to represent infinity
    pq.enqueue(src_vertex,0);
    while(!pq.isEmpty()){
        Node *min=pq.dequeue();//current node with minimum distance to source
        //check for each of the adjacent vertices of vertex min (exploration)
        //Note doing LinkedList curr=(ob.adj)[min->vertex] will return a copy object and not the original and hence wont work
        Node *temp=((ob.adj)[min->vertex]).get_head();//obtain head of Linked List of min vertex
        while(temp!=NULL){
            if(distance[temp->vertex]>distance[min->vertex]+temp->weight){
                distance[temp->vertex]=distance[min->vertex]+temp->weight;
                pq.enqueue(temp->vertex,distance[temp->vertex]);
            }
            temp=temp->next;
        }
        delete min; //freeing the popped node from the priority Queue
    }
    for(i=0;i<v;i++){
        std::cout<<distance[i]<<" ";
    }
    return 0;
}