// leetcode 1497

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
bool isKpair(vector<int> &v, int k){
    int n = v.size();
    vector<int> StoreMoudle(n,0);
    for(int i = 0 ; i < n ; i++){
       if(v[i]<0){
        StoreMoudle[i]=(v[i]%k+k)%k; 
       }
       else{
         StoreMoudle[i]=v[i]%k;
       }
    }
    unordered_map<int,int> mp ;// store element and its freq from StoreMoudle

    for(int ele:StoreMoudle){
        mp[ele]++;
    }
    // search for pair
    // k-mp.first should , if exists then both frequency should be same
    for(auto x : mp){
        int nextCouple = k - x.first;
        if(x.first==0) {
            if(x.second%2!=0) return false;
        }
        else if(mp.find(nextCouple)==mp.end()) return false;
        else {
            if(mp[nextCouple]!=x.second)return false;
        }
    }
    return true;

}
int main(){
    vector<int> v ;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);
    cout<<isKpair(v,5);
}