#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
// if cmp return true then a is palaced before b 
// if cmp return false then b is placed before a
bool cmp1(int a , int b){
    return a>b;
}
bool cmp2(int a, int b){
    return a<b;
}

bool cmp3(int a , int b){
    return abs(a)>abs(b);
    // sort integer by absolute value
}

bool cmp4(int a , int b){
    return abs(a)<abs(b);
}
bool cmp5(string a , string b){
    return a>b;
}
bool cmp6(string a, string b){
    return a<b;
}
bool cmp7(string a , string b){
    // sort stirng by length
    return a.length()<b.length();
}
int main(){
    vector<int> v = {1,3,-2,4,-33,2,5};
    for(int i =0 ; i< v.size() ; i++){
        cout<<v[i]<<" ";
    }
    sort(v.begin(), v.end(), cmp3);
    cout<<endl;
    for(int i = 0 ; i<v.size() ; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    vector<string> str= {"cat","battle",
    "rat"};
    for(int i =0 ; i<str.size() ; i++){
        cout<<str[i]<<" ";
    }
    cout<<endl;
    sort(str.begin(),str.end(),cmp5);
    for(int i =0 ; i<str.size() ; i++){
        cout<<str[i]<<" ";
    }
    cout<<endl;
    sort(str.begin(),str.end(),cmp7);
    for(int i =0 ; i<str.size() ; i++){
        cout<<str[i]<<" ";
    }


}