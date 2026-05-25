#include<bits/stdc++.h>
using namespace std;
int find(int a , vector<int> &parent){
    return parent[a]=parent[a]==a? a : find(parent[a],parent);
}
bool Union(int x , int y , vector<int>&rank , vector<int>&parent){
    x = find(x);
    y = find(y);
    if(x==y) return true;
    if(rank[x]>=rank[y]){
        rank[x]++;
        parent[y]=x;
    }
    else {
        rank[y]++;
        parent[x]=y;
    }
    return false;
}
int main(){

}