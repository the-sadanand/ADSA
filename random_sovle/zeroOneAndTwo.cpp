#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void zero_ones_two(vector<int>&v){
        int low =0 , mid =0 , high = v.size()-1; 
        int zero =0 , one = 0 , two = 0 ;
        while(mid<=high){
            if(v[mid]==0){
                swap(v[low],v[mid]);
                low ++ ;
                mid++ ;
            }
            else if(v[mid]==1) {
                mid++;
            }
            else {
                swap(v[mid],v[high]);
                high--;
            }
        }
        for(int i = 0 ; i<v.size() ; i++){
            cout<<v[i]<<" ";
        }
    }
};

int main(){
    Solution s;
    vector<int> v={1,0,0,0,2,1,1,1,2, 0};
    s.zero_ones_two(v);
}