#include<iostream>
#include<vector>
using namespace std;

// vector<vector<int>>dp(-1, 50);
int f(int dices, int face ,int target){
    if(dices ==0 && target==0) return 1;
    if(dices==0 && target!= 0) return 0;
    int sum =0;
    for(int value = 1 ; value<= face ; value++){
        sum =((sum)%mod + f(dices-1, face, target-value)%mod)%mod;
    }
    return sum;
}


int main(){
    int dices =1;
    int face =6;
    int target =3;
    cout<<f(dices,face, target);
}