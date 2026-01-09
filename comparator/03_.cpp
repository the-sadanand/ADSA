#include<bits/stdc++.h>
using namespace std;
bool cmp(int a , int b){
    // sort even first then odd 
    // multi - level logic
    if((a%2)!=(b%2)) 
    return a%2 ==0;
    return a<b;

}

int main(){
    vector<int> v = {3,4,22,3,4,33,266,36,9};
    for(int i =0 ; i< v.size() ; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    sort(v.begin(),v.end(),cmp);
    for(int i =0 ; i< v.size() ; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}