// set<int> s ; ordered set  , it will be sorted in increasing order , its generally take log(n) tc
// unordered_set <int> s; unordered set

#include<iostream>
#include<set>
#include<map>
using namespace std;
int main(){
    set<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(5);
    for(auto x : s){
        cout<<x<<" ";
    }
    cout<<endl;
    // lets see ordered map

    map<int, int> mIntInt;
    mIntInt[1]=2;
    mIntInt[4]=1;
    mIntInt[2]=5;
    for(auto x : mIntInt){
        cout<<x.first<<" : "<<x.second<<endl;
    }
    cout<<endl;
    map<char, int> mcharInt;
    mcharInt['A']=1;
    mcharInt['b']=2;
    mcharInt['D']=4;
    mcharInt['C']=3;
    for(auto x: mcharInt){
        cout<<x.first<<":"<<x.second<<endl;
    }
    cout<<endl;

}