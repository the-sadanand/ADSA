#include<iostream>
// #include<vector>
using namespace std;
class MinHeap{
    // not using arr o th index , 

    // idx will one more than the last element exist in array
    public:
    int arr[50];
    int idx ;
    MinHeap(){
        idx=1;
    }
    int top(){
        return arr[1];
    }
    void push(int x){
        arr[idx]=x;
        int i = idx;
        while(i!=1){
            int parent= i/2;
            if(arr[parent]>arr[i]){
                swap(arr[parent],arr[i]);
            }
            else break;
            int i = parent;
        }
    }
    int size(){
        return idx-1;
    }
};

