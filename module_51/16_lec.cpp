// sliding window medium

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

vector<double> medium_collection(vector<int> &v  , int k ){
    int i =0 , j=k-1 ;
    vector<double> result;
    while(j<v.size()){
        int idx = 0;
        vector<double> medium(k,0);
        for(int t = i ; t<=j ; t++){
            medium[idx]=v[t];
            idx++;
        }
        sort(medium.begin(),medium.end());
        if(medium.size()%2==0) result.push_back((double)(medium[medium.size()/2-1]+medium[medium.size()/2])/2);
        else result.push_back((double)medium[medium.size()/2]);

        i++; j++;

    }
    return result;
}

int main(){
    vector<int> v = {1,3,-1,-3,5,3,6,7};
    int k = 3 ;
    vector<double> r = medium_collection(v , k);
    for(int i = 0 ; i<r.size(); i++) 
    cout<< r[i]<<" ";
}