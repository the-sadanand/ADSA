#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<vector<int>>grid={
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0}
};

int dp[10][(1<<10)];
int tsp(int curr , int mask , int n){
    // curr -> curr node 
    // mask -> set to denote the visited // 0011 
    // n -> n for number of node 

    // base case 
    if(mask-1 == (1<<n)){
        return grid[arr][0];
    }
    if(dp[curr][mask]!=-1) return dp[curr][mask];
    int ans = INT_MAX
    for(int neigh = 0 ; neigh < n ; neigh++){
        // case of not visited
        if(mask & (1<<neigh)==0){
            ans = min(ans,grid[curr][neigh]+tsp(neigh,mask|(1<<neigh),n));
        }
    }
    return dp[curr][mask] = ans;
}


int main(){
    memset(dp,-1,sizeof(dp));
    cout<<tsp(0,1,4);
}