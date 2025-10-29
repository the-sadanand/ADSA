#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;
// generally this wroks only when given arr element is positive 
int  SubSumEqK(vector<int> & v , int k){
    int n = v.size();
    vector<int> preSum(n);
    preSum[0]=v[0];
    for(int i = 1 ; i <n ;i++){
        preSum[i]=v[i]+preSum[i-1];
    }
    for(int i =0 ; i<n ; i++){
        cout<<preSum[i]<<" ";
    }
    cout<<endl;
    unordered_set<int>s;
    int count=0;
    for(int i =0 ; i<n ;i++){
        if(preSum[i]<k) m[preSum[i]]++;
        else if(preSum[i]==k) {
            count++;
            m[preSum[i]]++;
        }
        else if(preSum[i]>k) {
                int req = preSum[i]-k;
                if(s.find(req)!=s.end()) count++;
                m[preSum[i]]++;
        }
    }
    return count;
}

int  TrueSubSumEqK(vector<int> & v , int k){
    int n = v.size();
    vector<int> preSum(n);
    preSum[0]=v[0];
    for(int i = 1 ; i <n ;i++){
        preSum[i]=v[i]+preSum[i-1];
    }
    for(int i =0 ; i<n ; i++){
        cout<<preSum[i]<<" ";
    }
    cout<<endl;
    unordered_map<int,int>m;
    int count=0;
    for(int i =0 ; i<n ;i++){
        if(preSum[i]==k) {
            count++;
        }
        
        int req = preSum[i]-k;
        if(m.find(req)!=m.end()) count+=m[req];
        m[preSum[i]]++;
    }
    return count;
}
int main(){
    vector<int > v ={0,0,0,0};
    cout<<TrueSubSumEqK(v,1);
}