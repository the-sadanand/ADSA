#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        Node* left ;
        Node* right;
        int count ;
        Node(){
            left=NULL;
            right=NULL;
            count = 0 ;
        }
};

class Trie{
    public:
    Node* root = new Node();
    void insert(int x){
        Node* curr = root ;
        curr->count++;
        for(int i = 30 ; i>= 0 ; i--){
            int bit = (x>>i) && 1 ;
            if(bit ==0 ){
                if(curr->left==NULL) curr->left = new Node();
                 curr = curr->left;
            } 
            else{
                if(curr->right ==NULL) curr->right = new Node();
                curr= curr->right;
            }
            curr->count++;
        }
    }
    void remove(int x ){
        Node* curr = root ;
        curr->count--;
        for(int i = 30 ; i>= 0 ; i--){
            int bit = (x>>i) & 1 ;
            if(bit==0) curr=curr->left;
            else curr= curr->right ;
            curr->count--;
        }
    }

    int maxXOR(int x){
        Node* curr = root;
        int ans = 0 ;
        for(int i = 30 ; i>=0 ; i++){
            int bit = (x>>i) & 1;
            if(bit == 0){
                if(curr->right !=NULL && curr->right-count >0 ){
                    ans +=(1<<i);
                    curr=curr->right;
                }
                else {
                    curr= curr->left;
                }
            }
            else {
                if(curr->left !=NULL && curr->left->count > 0){
                    ans+=(1<<i);
                    curr= curr->left;
                }
                else{
                    curr= curr->right;
                }
            }
        }
        return ans;
    }
};

int main(){
    int n ;
    cin>>n ;
    vector<int> arr(n);
    for(int &x : arr) cin>>x;
    int k ; cin>>k;
    Trie t;
    int ans = 0 ;
    for(int i = 0 ; i<n ; i++){
        if(i>0) t.insert(arr[i-1]);
        if(i-k-1>=0) t.remove(arr[i-k-1]);
        if(i>0) ans = max(ans , t.maxXOR(arr[i]));
    }
    cout<<ans;
    return 0 ;
}