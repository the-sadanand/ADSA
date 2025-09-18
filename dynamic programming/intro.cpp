#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class solution{
    public:
    // for recursive dp bottom up
    int helper(vector<int> &cost , int i , vector<int> &dp){
        if(i==0 || i==1) return cost[i];
        if(dp[i]!=-1) return dp[i];
        return dp[i]=cost[i]+min(helper(cost, i-1, dp),helper(cost , i-2,dp));
    }

    int minCostClimbingStairs(vector<int>&cost){
        int n= cost.size();
        vector<int> dp(n,-1);
        return min(helper(cost, n-1, dp),helper(cost , n-2,dp));
    }
    // tabulation method
    int minCostTlMethod(vector<int>&cost){
        int n = cost.size();
        for(int i = 2;i<n;i++){
            cost[i]=cost[i]+min(cost[i-1],cost[i-2]);
        }
        return min(cost[n-1],cost[n-2]);
    }
};

int main(){
    solution s;
    vector<int> stairs={1,3,4,1,5,6,1,1};
    cout<<s.minCostClimbingStairs(stairs)<<endl;
    cout<<s.minCostTlMethod(stairs);
    return 0;
}
