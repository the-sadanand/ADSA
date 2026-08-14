#include <bits/stdc++.h> 
using namespace std; 
 
class Node { 
public: 
    Node* child[2] = {NULL, NULL}; 
}; 
 
class Trie { 
public: 
    Node* root = new Node(); 
 
    void insert(int x) { 
        Node* cur = root; 
 
        for(int i = 30; i >= 0; i--) { 
            int bit = (x >> i) & 1; 
 
            if(cur->child[bit] == NULL) 
                cur->child[bit] = new Node(); 
 
            cur = cur->child[bit]; 
        } 
    } 
 
    int maxXOR(int x) { 
        Node* cur = root; 
        int ans = 0; 
 
        for(int i = 30; i >= 0; i--) { 
            int bit = (x >> i) & 1; 
            int opposite = 1 - bit; 
 
            if(cur->child[opposite]) { 
                ans |= (1 << i); 
                cur = cur->child[opposite]; 
            } 
            else { 
                cur = cur->child[bit]; 
            } 
        } 
 
        return ans; 
    } 
}; 
 
int main() { 
    int n; 
    cin >> n; 
 
    vector<int> arr(n); 
    for(int &x : arr) 
        cin >> x; 
 
    Trie t; 
 
    t.insert(arr[0]); 
 
    int ans = 0; 
 
    for(int i = 1; i < n; i++) { 
        ans = max(ans, t.maxXOR(arr[i])); 
        t.insert(arr[i]); 
    } 
 
    cout << ans; 
 
    return 0; 
}