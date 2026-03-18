#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std; 
unordered_set<int> s;
void keepSkip(vector<int>&v , int n , int sum){
    if(v.size()==n){
        cout<<sum<<" ";
        s.insert(sum);
        return;
    }
    keepSkip(v,n+1,sum+v[n]);
    keepSkip(v,n+1,sum);
}
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    keepSkip(v,0,0);
    cout<<endl;
    for(auto x : s){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<s.size();
}