// top  k Frequent Element

// let code 347 

// using map and min heap of that map 
// map store pair 
// solve 1636
#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
class Solutions{
public:
typedef pair<int, int> pi;
vector<int> topKFrequent(vector<int>&arr , int k){
    unordered_map<int, int> mp;
    
    // map pair is <ele, fre>
    for(int ele :arr){
        mp[ele]++;
    }
    // heap pair is <fre, ele>
    // priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
    priority_queue<pi, vector<pi> , greater<pi>> pq;
    for(auto x : mp){
        int ele = x.first , freq = x.second;
        pair<int,int> p = {freq, ele};
        pq.push(p);
        if(pq.size()>k) pq.pop();
    }
    vector<int> ans;
    while(pq.size()>0){
        int ele = pq.top().second;
        ans.push_back(ele);
        pq.pop();
    }
    return ans;
}
};