// leetcode 198

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// learning some recursive functions on a array
// int m = INT_MIN;
// int MaxInArray(vector<int> &v , int idx){
    // if(idx==-1) return m;
    // m = max(m,v[idx]);
    // MaxInArray(v,idx-1);
// }
// 
// Recursive Approach only

int fun(vector<int>&v,int idx){
    if(idx==v.size()-1) return v[v.size()-1];
    if(idx==v.size()-2) return max(v[v.size()-1],v[v.size()-2]);
    return max(v[idx]+fun(v,idx+2),0+fun(v,idx+1));
}
// using dp 
int funDP(vector<int>&v,int idx,vector<int>&dp){
    if(idx==v.size()-1) {
        dp[idx]=v[idx];
        return v[v.size()-1];
    }
    if(idx==v.size()-2) {
        dp[idx]= max(v[v.size()-1],v[v.size()-2]);
        return max(v[v.size()-1],v[v.size()-2]);
    }
    if(dp[idx]!=-1) return dp[idx];
    dp[idx]=max(v[idx]+funDP(v,idx+2,dp),0+funDP(v,idx+1,dp));
    return max(v[idx]+funDP(v,idx+2,dp),0+funDP(v,idx+1,dp));
}
int main(){
    vector<int> v;
   
    v.push_back(2);
    v.push_back(1);
    v.push_back(1);
    v.push_back(9);
    vector<int> dp(v.size()+5,-1);
    cout<<funDP(v,0,dp);

}
