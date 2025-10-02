// approx k sorted array 
// elemnt will dipacled x 
// where 0<= x <=k

// here we use max_heap
// in this problem , we are sorting from min to max we nedd mim ele at every pt. of time (min heap)
// size of heap should be <= k
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Solutions{
public:
    vector<int> approxKSort(vector<int> &v , int k){
        int n = v.size();
        priority_queue<int, vector<int> , greater<int> > pq;
        vector<int> ans;
        // for sc : 0 
        int idx =0 ;
        for(int i =0 ; i <n ; i++){
            pq.push(v[i]);
            if(pq.size()>k){
                ans.push_back(pq.top());
                // v[i++]= pq.top();
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;// return v;
    }
};
int main(){
    Solutions s;
    vector<int> v={1,3,2,5,4,6};
    vector<int> ans = s.approxKSort(v,2);
    for(int i =0 ; i<ans.size()  ; i++){
        cout<<ans[i]<<" ";
    }
}
