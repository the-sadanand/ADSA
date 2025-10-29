#include<iostream>
#include<vector>
using namespace std;
int rob(vector<int>&arr){
    int n = arr.size();
    if(n==1) return arr[0];
    if(n==2) return max(arr[0],arr[1]);
    vector<int> dp(3,0);
    dp[0]=arr[0];
    dp[1]=max(arr[0],arr[1]);
    for(int i=2 ; i<n;i++){
        dp[2]=max(dp[1],dp[0]+arr[i]);
        dp[0]=dp[1];
        dp[1]=dp[2];
    }
    return dp[2];
}
int main(){
    vector <int> v;
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    cout<<rob(v);
}