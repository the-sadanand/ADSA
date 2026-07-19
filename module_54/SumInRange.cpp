#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int>st;
void BuildST(int arr[], int i , int l , int h){
    if(l==h){
        st[i]=arr[l];
        return ;
    }
    int mid = l + (h-l)/2;
    BuildST(arr,2*i+1, l, mid);
    BuildST(arr,2*i+1,mid+1,h);
    st[i] = st[2*i+1]+st[2*i+2];
}

int rangeSum(int i , int lo , int hi , int l , int r){
    if(r<lo || hi<l) return 0;
    if(lo>=l && r<=hi) return st[i];
    int mid = lo + (hi-lo)/2;
    int leftSum =rangeSum(2*i+1 , lo , mid, l,r);
    int rightSum=rangeSum(2*i+2, mid+1 , hi,l,r);
    return leftSum+rightSum;

}

int main(){
    int arr[]= {2,3,4,5,3,2,2,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    BuildST(arr,0,0,n-1);
    cout<<rangeSum(0,0,n-1,2,3);
}