#include<iostream>
#include<climits>
using namespace std;
// Define a tree node

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=nullptr;
    }

};

// Traversals 

// In Order Traversal : left - root - right
void inOrderTraversal(Node* root){
    if(root==nullptr) return;
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}
// Pre Order Traversal  : root - left - right 

void PreOrderTraversal(Node* root){
    if(root==nullptr) return;
    cout<<root->data<<" ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}
// Post Order Traversal : right - left - root
void PostOrderTraversal(Node* root){
    if(root==nullptr) return;
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout<<root->data<<" ";  
}
// Level Order Traversal
void printLevel(Node* root , int level){
    if(!root) return;
    if(level==1) { 
        cout<<root->data<<" ";
    }
    else {
        printLevel(root->left,level-1);
        printLevel(root->right,level-1);
    }
}
// height of BST 
int height(Node* root){
    if(root==nullptr) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1+max(leftHeight,rightHeight);
} 

void levelOrder(Node* root){
    int h = height(root);
    for(int i =1 ;i<=h;i++){
        printLevel(root,i);
    }
}

// is BST is Valid Bst of not 
bool isBST(Node* root , long long Min , long long Max){
    if(root==nullptr) return true;
    if(Min && root->data <= Min) return false;
    if(Max && root->data>= Max) return false;
    return isBST(root->left, Min, root->data) &&
           isBST(root->right, root->data , Max);
}

// count the node in bst 
int countNodes(Node *root,int count){
    if(root==nullptr) return 0;
    count= 1+countNodes(root->left,count)+countNodes(root->right,count);
    // if(root->data == -1)count--;
    return count;
}

// level order using traversal a queue



int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right = new Node(15);
    root->right->left = new Node(13);
    root->right->left->left= new Node(11);
    // root->right->left->left->left= new Node(20);
    cout<<"\nPrint Level: ";
    printLevel(root,4);
    cout<<endl;
    inOrderTraversal(root);
    cout<<endl;
    PreOrderTraversal(root);
    cout<<endl;
    PostOrderTraversal(root);
    cout<<"\nHeight of Tree: ";
    cout<<"\nLevel order travesal: ";
    levelOrder(root);
    cout<<height(root)<<endl;
    if(isBST(root ,LLONG_MIN, LLONG_MAX)){
        cout<<"The Binary Tree is a BST ";
    }
    else {
        cout<<"The Binary Tree is not a BST ";
    }
    cout<<"\nNumber of nodes in given BST ";
    cout<<countNodes(root,0)<<endl;

    
}