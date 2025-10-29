#include<iostream>
#include<vector>
using namespace std;

int main(){
int m=0,n=0;
cout<<"Enter row and column";
cin>>m>>n;
vector<vector<int>> dp(m,vector<int>(n,1));
vector<vector<int>> ans(m,vector<int>(n,1));

for(auto x:dp){
    for(auto y: x){
        cout<<y<<" ";
    }
    cout<<endl;
}



// ans[i][j]=ans[i-1][j]+ans[i][j-1]

for(int i = 1 ; i<m ; i++){
    for(int j = 1 ; j<n ; j++){
        ans[i][j]=ans[i-1][j]+ans[i][j-1];
    }
}
cout<<" ans"<<endl;
for(auto r:ans){
    for(auto c: r){
        cout<<c<<" ";
    }
    cout<<endl;
}

return 0;
}

