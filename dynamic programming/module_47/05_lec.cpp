// c- vacations 
#include<bits/stdc++.h>
using namespace std; 
// one solutions:>J>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int res =0; 
vector<int> op;
void maxgain(int n , vector<vector<int>> &Grid, int row, int gain){
    if(row==n) {
        res = max(res, gain);
        return ;
    }
        for(int c=0 ; c<n ; c++){
            
            if(op[c]>=2) continue;
            op[c] +=1;
            maxgain(n, Grid , row+1,gain += Grid[row][c]);
            gain=gain-Grid[row][c];
            op[c]-=1;
        }
}

int main(){
    vector<vector<int>> v={{10,40,70},{20,50,80},{30,60,90}} ;
    op.resize(3,0);
    maxgain(3,v,0,0);
    cout<<res<<endl;
    cout<<"Bottom Up Approach "<<endl;
    int n;
    cin>>n;
    vector<vector<int>>dp(n,vector<int>(3,0));
    // base case
    int a, b , c;
    cin>>a>>b>>c;
    dp[0][0] = a;
    dp[0][1] = b;
    dp[0][2] = c;
    for(int i = 1 ; i<n ; i++){
        // input of happiness for ith day
        cin>>a>>b>>c;
        // ith day -> a
        dp[i][0] = a+max(dp[i-1][1],dp[i-1][2]);
        // ith day -> b 
        dp[i][1]= b+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = c+max(dp[i-1][1],dp[i-1][0]);
    }
    cout<<max(dp[n-1][0],dp[n-1][1],dp[n-1][2] );
    return 0;
}