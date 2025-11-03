#include<iostream>
#include<vector>
//to check if a tree is BST or not
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
    void insertion(int data);
    void bst_check_inorder(Node *temp,std::vector<int>&);
    void bst_check();
};

void BST::bst_check_inorder(Node *temp,std::vector<int> &arr){
    if(temp==NULL)return;
    else{
        bst_check_inorder(temp->left,arr);
        arr.push_back(temp->data);
        bst_check_inorder(temp->right,arr);
    }
}

void BST::bst_check(){
    std::vector<int> arr;int i;int flag=0;
    bst_check_inorder(root,arr);
    size_t vec_size=arr.size();
    for(i=0;i<vec_size-1;i++) if(arr[i]>arr[i+1]) flag=1;

    if(flag==0) std::cout<<"Tree is a BST"<<std::endl;
    else std::cout<<"Tree is not a BST"<<std::endl;
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

    tree.bst_check();

    return 0;
}
