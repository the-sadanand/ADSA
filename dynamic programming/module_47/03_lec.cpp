#include<iostream>
#include<vector>
using namespace std;
#define mod  10000000007
#define ll long long int

vector<ll> dp(1000005,-1);
ll NoOfCombinaitons(int n ){
    if(n==0) return 1;
    ll sum =0 ;
    if(dp[n] != -1) return dp[n];
    for(int i = 1  ; i<=6 ; i++){
        if(n-i<0) break;
            sum = (sum % mod +  NoOfCombinaitons(n-i) % mod) % mod;
    }
    return dp[n]=sum%mod;
}
int main(){
cout<<NoOfCombinaitons(3);
}