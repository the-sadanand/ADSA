#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
#include<algorithm>

using namespace std;

vector<vector<int>> grid = {
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0}
};

int dp[10][1<<10];

int tsp(int curr, int mask, int n)
{
    if(mask == (1<<n)-1)
        return grid[curr][0];

    if(dp[curr][mask] != -1)
        return dp[curr][mask];

    int ans = INT_MAX;

    for(int i=0;i<n;i++)
    {
        if((mask & (1<<i)) == 0)
        {
            ans = min(ans,
                      grid[curr][i] +
                      tsp(i, mask | (1<<i), n));
        }
    }

    return dp[curr][mask] = ans;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    cout << tsp(0,1,4);
}