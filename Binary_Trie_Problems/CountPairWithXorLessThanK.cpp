
/*
countLess(x, K) means: “How many numbers already present in the Trie have x ^ number < K?” It checks bits from 30 down to 0. At each bit, it looks at the current bit of x (xb) and K (kb). If K's bit is 0, then the XOR bit must also be 0, otherwise XOR would become greater than K, so we simply move to the branch that produces XOR 0. If K's bit is 1, we have two choices: if we make the XOR bit 0, then XOR becomes smaller than K at this bit, so every number in that entire branch is valid, and we add that branch's count directly to ans; then we move to the branch that makes XOR 1, because there the XOR is still equal to K so we need to check the remaining bits. In short: when K bit = 1 → count the branch producing XOR 0, then continue through the branch producing XOR 1; when K bit = 0 → only continue through the branch producing XOR 0.

*/

#include<bits/stdc++.h>

using namespace std;
class Node{
public:
    Node* left ;
    Node* right;
    int count ;
    Node(){
        left=right=NULL;
        count = 0 ;
    }
};

class Trie{
    public:
    Node* root ;
    void insert(int x){
        Node* curr = root;
        curr->count++;
        for(int i = 30 ; i>= 0 ; i--){
            int bit = (x>>i) & 1 ;
            if(bit==0) {
                if(curr->left==NULL) curr->left = new Node();
                 curr = curr->left;
            }
            else{
                if(curr->right ==NULL) curr->right = new Node();
                curr = curr->right;
            }
            curr->count++;
        }
    }
    int maxXOR(int x){
        Node* curr = root ;
        int ans=0 ; 
        for(int i = 30 ; i>= 0 ; i--){
            int bit = (x>>i) &1;
            if(bit == 0){
                if(curr->right != NULL ){
                    ans +=(1<<i) ;
                    curr = curr->right;
                }
                else curr= curr->left;
            }
            else {
                if(curr->left!=NULL){
                    ans+=(1<<i);
                    curr=curr->left;
                }
                else curr= curr->right;
            }
        }
        return ans;
    }

    int ContLessK(int x , int k){
        Node* curr = root;
        for(int i = 30 ; i>= 0 ; i--){
            if(curr=NULL) break;
            int xb = (x>>i) & 1; 
            int kb = (k>>i) & 1;
            if(kb == 1){
                if(xb==0){
                if(curr->left != NULL) ans += curr->left->count;
                curr = curr->right;
            }
            else{
                if(curr->right !=NULL) ans+=curr->right->count;
                curr = curr->left;
            }
        }
        else {
            if(xb==0) curr->left;
            else curr = curr->right;
        }
        }
        return ans ;
    }
}; 

int main(){
    int n ;
    cin>>n ;
    vector<int> arr(n);
    for(int &x : arr) cin>>x;
    int k ; cin>> k ; Trie t;
    long long ans = 0 ;
    for(int i = 0 ; i<n ; i++){
        ans += t.ContLessK(arr[i],k);
        t.insert(arr[i]);
    }
    cout<<ans;
    return 0 ;
}