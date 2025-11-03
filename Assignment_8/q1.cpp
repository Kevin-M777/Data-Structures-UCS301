#include<iostream>
//implementing the various traversals of Binary Trees

class Node{
    public:
    int data;
    Node *left;
    Node * right;
    Node(int data){this->data=data;left=NULL;right=NULL;}
};

class BST{
    Node *root;
    public:
    BST(){root=NULL;}
    void preorder(Node *temp);
    void postorder(Node *temp);
    void inorder(Node *temp);
};

void BST::preorder(Node *temp){
    if(temp==NULL)return;
    else{
        std::cout<<temp->data<<" "; 
        preorder(temp->left);
        preorder(temp->right);
    }
}

void BST::postorder(Node *temp){
    if(temp==NULL)return;
    else{
        postorder(temp->left);
        postorder(temp->right);
        std::cout<<temp->data<<" ";
    }
}

void BST::inorder(Node *temp){
    if(temp==NULL)return;
    else{
        inorder(temp->left);
        std::cout<<temp->data<<" ";
        inorder(temp->right);
    }
}