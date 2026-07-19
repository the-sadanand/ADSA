#include<bits/stdc++.h>
using namespace std;

int bitcount(int n){
    int cnt =0 ; 
    while(n){
        n&=(n-1);
        cnt++;
    }
    return cnt;
}

int main(){

    cout<<bitcount(23);
    // print all set

    vector<int> v {1,2,3};
    for(int mask =0 ; mask<(1<< v.size()) ; mask++){
        for(int i = 0 ; i < v.size() ; i++) {
            if(mask & (1<<i)) cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}