#include<iostream>
#include<algorithm> //for std::max() in height function

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
    BST(){root=NULL;} 
    Node *get_root(){return root;}
    void inorder(Node *temp);
    int height(Node *node);
    int max_depth();
    int min_depth();
    Node *minimum(Node *temp);
    Node *successor(Node *temp);
    void insertion(int data);
    void deletion(Node *temp);
     Node *search_iter(Node *temp, int num);
};

Node *BST::minimum(Node *temp){ //accepts the root of the subtree in which you want to find the minimum
    while(temp->left!=NULL) temp=temp->left;
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

void BST::deletion(Node *temp){
    Node *y;Node *x;
    if(temp->left==NULL || temp->right==NULL) y=temp;//if node to be deleted has 0 or 1 child
    else y=successor(temp); //have taken successor, could use predecessor too, prefer the simpler case (ie whoever has a smaller subtree below it)
    
    //now y is for sure a node with either 0 or 1 child, y is to be deleted
    if(y->left!=NULL) x=y->left; //if y has one child then store that one child in x
    else x=y->right;
    //if y has no children then x will be NULL

    if(x!=NULL) x->parent=y->parent; //make x's parent = y's parent
    if(y->parent==NULL)this->root=x; //if y was the root, then x should become the root

    if(y->parent->left==y) y->parent->left=x; //complete the parent child connection
    else y->parent->right=x;

    if(y!=temp){
        //copy data from y to temp
        temp->data=y->data;
        //NOTE: dont copy the parent,left or right pointers, they will all remain the same
        free(y);
    }
    else{
        free(y);
    }
}

int BST::height(Node *node){//finds the height of any node
    if(node==NULL)return -1; //important to return -1 and not 0 else you will calculate actual height + 1
    else{
        int left_ht= height(node->left);
        int right_ht= height(node->right);
        return std::max(left_ht,right_ht)+1;
    }
}

//to calculate max depth of BT just calculate height of root node
int BST::max_depth(){
    return height(root);
}

int BST::min_depth(){
    if(root==NULL) std::cout<<"Tree is empty!"<<std::endl;
    else if(root->left==NULL && root->right==NULL) return 0;
    else return 1; //min depth will be 1 if root has atleast one child
}

Node *BST::search_iter(Node *temp, int num){
    while(temp!=NULL){
        if(temp->data==num) return temp;
        else if(num<temp->data) temp=temp->left;
        else temp=temp->right;
    }
    return NULL;
}

void BST::inorder(Node *temp){
    if(temp==NULL)return;
    else{
        inorder(temp->left);
        std::cout<<temp->data<<" ";
        inorder(temp->right);
    }
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

    Node *search_node= tree.search_iter(root,10);
    
    if(search_node!=NULL) std::cout<<search_node->data<<std::endl;
    else std::cout<<"Node not found"<<std::endl;

    tree.inorder(root);std::cout<<"\n";
    tree.deletion(search_node); //deletes node with value 10
    tree.inorder(root);//after deletion

    std::cout<<tree.min_depth()<<std::endl;
    std::cout<<tree.max_depth()<<std::endl;

    return 0;
}