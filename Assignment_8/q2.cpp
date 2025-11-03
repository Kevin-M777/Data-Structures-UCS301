#include<iostream>

class Node{
    public:
    int data;
    Node *parent;
    Node *left;
    Node * right;
    Node(int data){this->data=data;left=NULL;right=NULL;}
};

class BST{
    Node *root;
    public:
    BST(){root=NULL;} //very important, dont do root->parent=NULL etc as then you will be dereferencing a NULL pointer
    Node *get_root(){return root;}
    Node *minimum(Node *temp);
    Node *maximum(Node *temp);
    Node *successor(Node *temp);
    Node *predecessor(Node *temp);
    Node *search_rec(Node *temp, int num);
    Node *search_iter(Node *temp, int num);
    void insertion(int data);
};

Node *BST::search_rec(Node *temp, int num){ //temp is initially root
    if(temp==NULL) return NULL; //means element not found, must check this first to avoid dereferencing a NULL leading to segmentation fault
    else if(temp->data==num) return temp; //means element found and return address of its node
    else if(num<temp->data) return search_rec(temp->left, num);
    else return search_rec(temp->right,num);
}

Node *BST::search_iter(Node *temp, int num){
    while(temp!=NULL){
        if(temp->data==num) return temp;
        else if(num<temp->data) temp=temp->left;
        else temp=temp->right;
    }
    return NULL;
}

Node *BST::minimum(Node *temp){ //accepts the root of the subtree in which you want to find the minimum
    while(temp->left!=NULL) temp=temp->left;
    return temp;
}

Node *BST::maximum(Node *temp){
    while(temp->right!=NULL) temp=temp->right;
    return temp;
}

Node *BST::successor(Node *temp){
    if(temp->right!=NULL){ //if node has a right subtree
        return minimum(temp->right);
    }
    else{
        Node *y=temp->parent;Node *x=temp;
        while(y!=NULL && y->right==x){
            x=y;
            y=y->parent;
        }
        if(y==NULL)return temp; //ie temp does not have a successor as it is itself the max node
        else return y;
    }
}

Node *BST::predecessor(Node *temp){
    if(temp->left!=NULL){ //if node has a left subtree
        return maximum(temp->left);
    }
    else{
        Node *y=temp->parent;Node *x=temp;
        while(y!=NULL && y->left==x){
            x=y;
            y=y->parent;
        }
        if(y==NULL)return temp; //ie temp does not have a predecessor as it is itself the min node
        else return y;
    }
}

void BST::insertion(int data){
    Node *newnode= new Node(data);//allocate on heap and not on stack else you will end up with a dangling pointer later on
    Node *y=NULL;
    Node *x=this->root;
    while(x!=NULL){
        y=x;
        if(newnode->data < x->data) x=x->left;
        else x=x->right;
    }
    //loop will stop with y pointing to the node who will be the parent of the newnode we are inserting
    
    newnode->parent=y;//works even if tree was empty ie y remained NULL, as now newnode will be the root and thus its parent should be NULL

    if(y==NULL)this->root=newnode;//if tree was empty
    else if(newnode->data < y->data) y->left=newnode;
    else y->right=newnode;
}

int main(){
    BST tree;int i;
    
    tree.insertion(8);
    tree.insertion(3);
    tree.insertion(1);
    tree.insertion(10);
    tree.insertion(6);
    tree.insertion(14);
    tree.insertion(4);
    tree.insertion(7);
    tree.insertion(13);
 
    Node *root=tree.get_root();

    Node *search_node= tree.search_iter(root,8);   //have taken value 8 for example 
    
    if(search_node!=NULL) std::cout<<search_node->data<<std::endl;
    else std::cout<<"Node not found"<<std::endl;

    Node *max=tree.maximum(root);
    Node *min=tree.minimum(root);
    std::cout<<"Max: "<<max->data<<" Min: "<<min->data<<std::endl;

    Node *pre=tree.predecessor(root);
    Node *suc=tree.successor(root);
    std::cout<<"Successor: "<<suc->data<<" Predecessor: "<<pre->data<<std::endl;

    return 0;
}
