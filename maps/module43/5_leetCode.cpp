// Nice pairs
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution{
public:
    int rev(int n){
        int r=0;
        while(n>0){
            int digit = n%10;
            r=r*10+digit;
            n=n/10;
        }
    }
    int combo(int n){
        return n*(n-1)/2;
    }
    int NoOfNicePairs(vector<int> &v){
        int n = v.size();
        int count=0;
        for(int i =0 ; i<n-1 ;i++){// this solution will take n*2 tc
            for(int j=i; j<n;j++){
                if(v[i]+rev(v[j])==v[j]+rev(v[i]))
                    count++;
            }
        }
    }
    // optimize way
    int NoOfNicePairsOpt(vector<int> &v){
        int n = v.size();
        unordered_map<int,int> m;
        int count=0;
        for(int i =0 ; i<n ;i++){
            v[i]=v[i]-rev(v[i]);
        }
        for(int i =0 ; i<n ;i++){
            m[v[i]]++;
        }

        int count=0 ; 
        for(auto x : m){
            count+=combo(m.second);
        }

    }    
};
int  main(){
    Solution s;
    vector<int>v;
    v.push_back(1);
    v.push_back(11);
    cout<<s.NoOfNicePairs(v) ;
}