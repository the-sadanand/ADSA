#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void usingSorting(vector<int>&v){
        sort(v.begin(),v.end());
        for(int x : v){
            cout<<x<<" ";
        }
    }

    void usingCount(vector<int>&v){
        int count_zero=0 ; 
        for(int i =0 ; i<v.size() ; i++) if(v[i]==0) count_zero++;
        for(int i =0 ; i<count_zero ; i++) v[i]=0;
        for(int i = count_zero ; i<v.size() ; i++) v[i]=1;
        for(int i = 0 ; i<v.size() ; i++) cout<<v[i]<<" ";
    }
    void usingTwoPointer(vector<int>&v){
      int i = 0 , j = v.size()-1; 
      while(i<j){
        while(i<j && v[i]==0) i++;
        while(i<j && v[j]==1) j--;
        if(i<j){
            swap(v[i],v[j]);
            i++;
            j--;
        }
      } 
      for(int i =0 ; i<v.size(); i++){
        cout<<v[i]<<" ";
      } 
    }
    void moveAllNeg(vector<int>&v){
        int i = 0 , j = v.size()-1; 
        while(i<j){
            while(i<j && v[i]>0) i++;
            while(i<j && v[j]<0) j--;
            if(i<j) {
                swap(v[i],v[j]);
                i++;
                j--;
            }
        }
        for(int i = 0 ; i<v.size() ; i++){
            cout<<v[i]<<" ";
        }
    }
  };


int main(){
    vector<int> v = {0,0,1,0,1,0};
    Solution s;
    s.usingTwoPointer(v);
    cout<<endl;
    vector<int>vneg= {2,-3,4,5,0, -1, -5};
    s.moveAllNeg(vneg);
}