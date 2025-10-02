class Solution {
public:
    typedef pair<int, vector<int>> piv;
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
    priority_queue<piv>pq;// max heap
    for(vector<int> v : arr){
        int x = v[0];// x 
        int y = v[1];// y 
        int dist = x*x+y*y;
        pq.push({dist,v});// push pair : distance from
        //  origian and point as form of vector
        if(pq.size()>k)pq.pop();
    }
    vector<vector<int>> ans;
    while(pq.size()>0){
        vector<int> v = pq.top().second;
        ans.push_back(v);
        pq.pop();
    }
    return ans;
    }
};