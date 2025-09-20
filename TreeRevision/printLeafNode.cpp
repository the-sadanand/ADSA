#include<iostream>
#include<queue>
#include<vector>

using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data  = val;
        left = right = nullptr;
    }
};
Node* createNode(Node* root ,int val){
        if(!root) return new Node(val);
        if(val<root->data){
            root->left= createNode(root->left,val);
        }
        else if(val>root->data){
            root->right = createNode(root->right, val);
        }
        return root;
}
// pre order 
void preOrder(Node* root, vector<int>&v){
    if(!root) return;
    preOrder(root->left,v);
    v.push_back(root->data);
    preOrder(root->right, v);
}

// print level Order using queue and storing each level node in a two D vecotr
void levelOrder(Node* root, vector<vector<int>>&v){
        if(!root) return ;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int levelSize = q.size();
              vector<int> LevelVector(levelSize);
            for(int i =0 ;i<levelSize ; i++){
                Node* curr = q.front();
                q.pop();
                cout<<curr->data<<" ";
                LevelVector[i]=(curr->data);    
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            v.push_back(LevelVector);
            cout<<endl;
        }
}

// Searching of Node 
int SearchNode(Node* root, int val){
    if(!root) return -1;
    if(root->data==val) return 1;
    if(root->data>val) return SearchNode(root->left, val);
    else return SearchNode(root->right,val);
}
int NoOfLeafNode(Node* root){
    if(!root) return 0;
    if(!root->left && !root->right) {
        cout<<root->data<<" ";
        return 1;
    }
    return NoOfLeafNode(root->left) + NoOfLeafNode(root->right);
}
int CountLevelNode(Node* root, int k){
        if(!root) return 0;
        if(k==0 ) return 1;
        return CountLevelNode(root->left,k-1)+CountLevelNode(root->right,k-1);
}
int main(){
        // start root of tree 
        Node* root = new Node(23);
        root=createNode(root, 30);
        root=createNode(root, 35);
        root=createNode(root,1);
        root=createNode(root,2);
        cout<<endl;
        cout<<"no of node at given level: ";
        cout<<CountLevelNode(root,1)<<endl;
        cout<<"Level Order "<<endl;
        vector<vector<int>> ans;
        // level Order Printing 
        levelOrder(root,ans);
        // Print Vector for Every level
        cout<<endl;
        cout<<"from vector"<<endl;
        for(int i =0 ; i<ans.size();i++){
            for(int j =0 ; j< ans[i].size();j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
        // Number of leaf Nodes in Binary Tree
        cout<<endl;
        cout<<"Leaf Nodes are: ";
        cout<<"\nNumbers of Leaf Node: "<<NoOfLeafNode(root);
        cout<<"\n Storing pre Order in a vector: ";
        vector<int> PreVector;
        preOrder(root,PreVector);
        for(int i =0 ; i<PreVector.size();i++){
            cout<<PreVector[i]<<" ";
        }
        cout<<endl;
        // Searching the node in BST
        root = createNode(root,12);
        int found =SearchNode(root , 12);
        if(found==-1){
            cout<<"Node doesn't exists"<<endl;
        }
        if(found == 1){
            cout<<"Node exists"<<endl;
        }
       
}