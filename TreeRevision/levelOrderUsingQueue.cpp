#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left ;
    Node* right;
    Node(int val){
        data = val;
        left=right=nullptr;
    }

    // Node(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

void levelOrder(Node* root){
    if(!root) return;
    // hey when you think in negation you get stuck thing in term it false or true
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int levelSize= q.size();
        for(int i=0 ;i<levelSize ; i++){
            Node* root =q.front();
            q.pop();
            cout<<root->data<<" ";
            if(root->left)q.push(root->left);
            if(root->right)q.push(root->right);
        }
    cout<<endl;
    }
}

// Add new Node 

Node* AddNode(Node* root, int val){
   
    if (!root){
         return new Node(val);
    }
    if(val < root->data) {
        root->left = AddNode(root->left , val);
    }
    else if(val>root->data) root->right = AddNode(root->right, val);
    return root;
}
int main(){
    Node* root = new Node(23);
    root->left= new Node(12);
    root->left->left= new Node(5);
    root->right = new Node(24);
    root = AddNode(root, 25);
    root= AddNode(root,30);

    // print level order element 
    levelOrder(root);
}