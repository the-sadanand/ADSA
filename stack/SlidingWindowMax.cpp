#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>  maxSlidingWindow(vector<int> arr , int k){
        // Brute force method 
        // vector<int> ans;
        // int n = arr.size();
        // for(int i=0 ; i<n-k+1;i++){
            // int mx = INT16_MIN;
            // for(int j=i; j <i+k ;j++){
                // mx = max(mx,arr[j]);
            // }
            // ans.push_back(mx);
        // }
        
        // method 2 : using a stack

        // for each elemet find next greater element index in a spearate arr

        vector<int>ans ;
        int n = arr.size();
        int ngi[n];
        stack<int> st;
        ngi[n-1] = n;
        st.push(n-1);
        for( int i =n-2 ; i>=0 ;i--){
            while(st.size()>0 && arr[st.top()]<arr[i]){
                st.pop();
            }
            if(st.size()==0) ngi[i]=n;
            else ngi[i] = st.top();
            st.push(i);
        }
        
        int j=0;
        for(int i=0; i<n-k+1 ;i++){
            if(j<i) j=i;
            int mx = max(mx,arr[j]);
            while (j < i+k)
            {

                // firstly we have next greater index arry 
                // with ngi will cheak at present elemetn in given array next is in range of not if it yes then j point that next greater 
                mx = arr[j];
                if(ngi[j]>= i+k) break;
                j = ngi[j];
            }
            ans.push_back(mx);
            
        }
        return ans;
    }
  
};

int main() {
    Solution sol;

    // Example input
    vector<int> arr = {10, 6, 8, 5, 11, 9};
    int k =3;

    // Call function
    vector<int> result = sol.maxSlidingWindow(arr, k);

    // Print output
    cout << "Result: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
