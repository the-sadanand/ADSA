#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std; 

int main(){
 vector<int> v {1,2,3,3,3,3,1,1,4,4};
 unordered_map<int,int>mp ;
 for(int i =0 ; i<v.size() ; i++){
    mp[v[i]]++;
 }
//  cout<<mp[1];
 int result =0 ;
 for(auto ele : mp){
    // cout<<ele.second<<" ";
    result=result+ele.second/2;
 }
 cout<<result;

}