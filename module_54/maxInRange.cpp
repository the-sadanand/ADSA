// segment tree 

#include<iostream>
#include<vector>
using namespace std ;

vector<int> st;

void BuildST(int arr[],int i , int lo , int hi){
        if(lo==hi){
            st[i]=arr[lo];
            return ;
        }
        BuildST(arr,2*i+1,lo,mid);
        BuildST(arr,2*i+2,mide+1,hi);
        st[i]=max(st[2*i+1],st[2*i+2]);
}