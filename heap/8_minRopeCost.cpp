
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Solutions{
public:
   int  minRopeCost(vector<int> &v){
        int n = v.size();
        int minCost=0;
        priority_queue<int, vector<int> , greater<int> > pq;
        for(int i =0 ; i < n ;i++){
            pq.push(v[i]);
        }
        while(pq.size()>1){
            int firstRope= pq.top(); pq.pop();
            int secondRope = pq.top(); pq.pop();
            pq.push(firstRope+secondRope);
            minCost+=firstRope+secondRope;
        }
        return minCost;
    }
};
int main(){
    Solutions s;
    vector<int> v;
    v.push_back(6);
    v.push_back(5);
    v.push_back(3);
    v.push_back(2);
    v.push_back(8);
    v.push_back(10);
    v.push_back(9);
    cout<<s.minRopeCost(v);
}
