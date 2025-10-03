/*
Algorithm for Top View of Binary Tree:

1. Construct the binary tree from the given array (use INT_MIN for null nodes).
2. Use level order traversal (BFS) to visit each node.
3. Track the horizontal distance (hd) of each node from the root:
   - Root has hd = 0
   - Left child: hd - 1
   - Right child: hd + 1
4. For each horizontal distance, store the first node encountered (topmost node).
5. Use a map to store hd -> node value.
6. After traversal, print the node values from the leftmost to rightmost hd.

Each step in the code is commented below.
*/

#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val= val;
        this->left= NULL;
        this->right=NULL;
    }
};

// Level: Construct tree from array using queue (BFS)
Node* construct(int arr[], int n){
    queue<Node*>q;
    Node* root= new Node(arr[0]);
    q.push(root);
    int i = 1; int j = 2;
    while(q.size()> 0 && i < n){
        Node* temp = q.front();
        q.pop();
        Node* l;
        Node* r;
        // Level: Assign left child if not INT_MIN
        if(arr[i]!=INT_MIN) l = new Node(arr[i]);
        else l = NULL;
        // Level: Assign right child if not INT_MIN
        if(j!=n && arr[j]!=INT_MIN) r= new Node(arr[j]);
        else r=NULL;
        temp->left = l;
        temp->right = r;
        // Level: Push children to queue for next level
        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);
        i+=2;
        j+=2;
    }
    return root;
}

// Level: Top view using BFS and horizontal distance
void topview(Node* root){
    if(!root) return;
    unordered_map<int,int> m; // hd -> node value
    queue< pair<Node* , int> > q;
    pair<Node* , int> r;
    r.first = root;
    r.second = 0; // Level: Root at hd = 0
    q.push(r);
    m[0]= root->val;
    int min_hd = 0, max_hd = 0;
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        Node* node = front.first;
        int hd = front.second;
        // Level: Store first node at each hd (topmost node)
        if(m.find(hd) == m.end()) {
            m[hd] = node->val;
        }
        // Level: Update min/max hd for printing range
        min_hd = min(min_hd, hd);
        max_hd = max(max_hd, hd);
        // Level: Add left child with hd-1
        if(node->left) q.push({node->left, hd-1});
        // Level: Add right child with hd+1
        if(node->right) q.push({node->right, hd+1});
    }
    // Level: Print top view from leftmost to rightmost hd
    for(int i = min_hd; i <= max_hd; ++i){
        if(m.find(i) != m.end())
            cout << m[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] ={1,2,3,4,5,INT_MIN,6,INT_MIN,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr,n);
    topview(root);
}