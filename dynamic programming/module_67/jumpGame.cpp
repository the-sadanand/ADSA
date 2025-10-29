



#include<iostream>
#include<vector>
using namespace std;

// a bool functions to tell is it possible to reach last index of vector
// value of each index give power to jump maximum jump
vector<int>dp;
bool f(vector<int> &v , int idx){
    if(idx>= v.size()-1) return true;
    if(dp[idx]!=1) return dp[idx];
    bool ans = false;
    if(v[idx]>= v.size()-1-idx) return true;
    for(int i = 1 ; i <=v[idx] ; i++){
        ans = ans || f(v, idx+i);
    }
    return dp[idx]=ans;
}
int main(){
    
    vector<int> v = { 1,2,3,4};
    dp.resize(v.size(),-1);
    cout<<f(v,0);
}