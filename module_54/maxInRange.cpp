// segment tree 

#include<iostream>
#include<vector>
#include<climits>
using namespace std ;

vector<int> st;

void BuildST(int arr[],int i , int lo , int hi){
        if(lo==hi){
            st[i]=arr[lo];
            return ;
        }
        int mid = lo + (hi-lo)/2;
        BuildST(arr,2*i+1,lo,mid);
        BuildST(arr,2*i+2,mid+1,hi);
        st[i]=max(st[2*i+1],st[2*i+2]);
}

int getMax(int i , int lo , int hi , int &l , int &r){
    // l and r user query range 
    // case of Outside 
    if(l>hi || r<lo) {
        return INT_MIN;
    }
    // case of query range  is completely or equal to  range
    if(lo>=l && hi<=r) {
        return st[i];
    }
    int mid = lo + (hi-lo)/2;
    int leftMax = getMax(2*i+1 , lo, mid , l,r);
    int rightMax = getMax(2*i+2,mid+1,hi,l,r);
    return max(leftMax,rightMax);
}

int main(){
    int arr[]={1,4,2,8,6,4,9,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    st.resize(4*n);
    BuildST(arr,0,0,n-1);
    int q;cin>>q;
    while(q--){
        int l,r;
        cout<<"Enter the range:";
        cin>>l>>r;
        cout<<getMax(0,0,n-1,l,r)<<endl;
    }
}