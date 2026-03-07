#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int next_great_permutation(int n){
    vector<int>arr;
    int real=n;
    while(n>0){
        int d = n%10;
        n=n/10;
        arr.push_back(d);
    }
    reverse(arr.begin(),arr.end());
    // search for arr[i]<arr[i+1];
    int st = -1 ;
    for(int i = 0 ; i < arr.size()-1 ; i++){
        if(arr[i]<arr[i+1]){
            st=i;
        }
    }
    if(st!=-1) { 
        swap(arr[st],arr[st+1]);
        sort(arr.begin()+st+1 , arr.end());
    }
    else return real;
    int next =0 ;
    for(int i=0 ; i<arr.size(); i++){
        next = next*10 +arr[i];
    }
    
    return next;
}

int main(){

    cout<< next_great_permutation(34210);
    
}