// find kth sortest element from array

// method-1; sort arr[k-1] nlogn 
//selections sor k*n
// quick sort tc n 
// using heap Tc nlogk

#include<iostream>
#include<queue>
using namespace std;

// using max_heap
// store k element in max_heap on exceeding more than k pop again push on it , after that till all element push , the top of max heap will answer
int kthMin(vector<int> &v, int k){
    priority_queue<int>max_heap;
    for(int i =0 ; i<v.size() ; i++){
        max_heap.push(v[i]);
        if(max_heap.size()>k && max_heap.size()!=0) max_heap.pop();
    }
    return max_heap.top();
}
int main(){
    vector<int>v={11,2,13,4,-115,611,7};
    cout<<kthMin(v,1);
}