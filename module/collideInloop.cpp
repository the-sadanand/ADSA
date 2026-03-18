#include<iostream>
#include<vector>
using namespace std; 
void collideAt(vector<int> &v){
    for(int i=0 ,j=v.size()-1; i<v.size() , j>=0 ; i++ ,j--){
        if(v[i]==v[j]){
            cout<<"Collide happen"<<"at "<< i <<"and "<<v[i];
        }
    }
    return ;
}
int main(){
    vector<int> v = {1,2,3,4,4};
    collideAt(v);
}