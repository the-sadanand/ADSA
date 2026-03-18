#include<iostream>
#include<unordered_map>
#include<vector> 
#include<string>
using namespace std;

void already_exists(string s){
    unordered_map<char, int> mp;
    for(char c:s){
        if(mp.count(c)){
            cout<<c<<" already exists"<<endl;
        }
        mp[c]++;
        cout<<mp[c]<<" "<<endl;
    }
}

int main(){
    already_exists("abcac");
}