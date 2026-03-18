#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> v = {1,1,2,2,3,5};

    int xr = 0;

    for(auto nums : v){
        xr ^= nums;
    }

    int different_bits = xr & (-xr);

    int x = 0, y = 0;

    for(auto nums : v){
        if((nums & different_bits) == 0)
            x ^= nums;
        else
            y ^= nums;
    }

    cout << x << " " << y;
}