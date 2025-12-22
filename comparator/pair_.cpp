#include<bits/stdc++.h>
using namespace std;
// comparator : sort by second element of pair(ascending)

bool cmp1(pair<int,int> a , pair<int,int> b){
    return a.second<b.second;
}
bool cmp2(pair<int,int>a , pair<int,int> b){
    return a.second>b.second;
}

bool cmp3(pair<int,int> a , pair<int, int> b){
    if(a.second==b.second) 
    return a.first<b.first;
    return a.second<b.second;
}

int main(){
    vector<pair<int,int>> v = {
        {5,5},
        {2,5},
        {4,1},
        {6,3}
    };
    // sort using custom comparator

    sort(v.begin(), v.end(), cmp3);
    // print result
    for(auto p : v){
        cout<<"{"<<p.first <<" ,"<<p.second<<"}";
    }
    return 0;
}