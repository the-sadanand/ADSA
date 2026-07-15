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
        idx++;
        while(i!=1){
            int parent= i/2;
            if(arr[parent]>arr[i]){
                swap(arr[parent],arr[i]);
            }
            else break;
            int i = parent;
        }
    }

    void pop(){
        idx--;
        arr[1]=arr[idx];
        int i = 1; 
        while(true){
            int left = 2*i , right = 2*i+1;
            if(left>idx-1) break;
            if(right>idx-1){
                if(arr[i]>arr[left]){
                    swap(arr[i],arr[left]);
                    i=left;
                }
                break;
            }
            if(arr[left]>arr[right]){
                if(arr[i]>arr[left]){
                    swap(arr[i],arr[left]);
                    i=left;
                }
                else break;
            }
            else {
                if(arr[i]>arr[right]) {
                    swap(arr[i],arr[right]);
                    i=right;
                }
                else break;
            }
        }
    }

    void display(){
        for(int i = 1 ; i<= idx-1 ; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    int size(){
        return idx-1;
    }
};

int main(){
    MinHeap pq;
    pq.push(10);
    pq.push(20);
    // pq.push(1);
    cout<<pq.size()<<endl;
    pq.push(4);
    cout<<pq.top()<<endl;
}

