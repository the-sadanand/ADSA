// maximum XOR queries 


#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    Node* left;   // 0
    Node* right;  // 1

    Node() {
        left = NULL;
        right = NULL;
    }
};

class Trie {
public:
    Node* root = new Node();

    void insert(int x) {
        Node* cur = root;

        for(int i = 30; i >= 0; i--) {

            int bit = (x >> i) & 1;

            if(bit == 0) {
                if(cur->left == NULL)
                    cur->left = new Node();

                cur = cur->left;
            }
            else {
                if(cur->right == NULL)
                    cur->right = new Node();

                cur = cur->right;
            }
        }
    }

    int maxXOR(int x) {
        Node* cur = root;
        int ans = 0;

        for(int i = 30; i >= 0; i--) {

            int bit = (x >> i) & 1;

            if(bit == 0) {

                // Want 1
                if(cur->right != NULL) {
                    ans += (1 << i);
                    cur = cur->right;
                }
                else {
                    cur = cur->left;
                }
            }
            else {

                // Want 0
                if(cur->left != NULL) {
                    ans += (1 << i);
                    cur = cur->left;
                }
                else {
                    cur = cur->right;
                }
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

    // Insert all array elements
    Trie t;

    for(int x : arr)
        t.insert(x);

    int q;
    cin >> q;

    while(q--) {

        int x;
        cin >> x;

        cout << t.maxXOR(x) << endl;
    }

    return 0;
}