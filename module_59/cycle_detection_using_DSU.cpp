#include<bits/stdc++.h>
using namespace std;
int find(vector<int> &parent , int x){
    return parent[x]=parent[x]==x ? x : find(parent,x);
}

bool Union(vector<int>&parent,vector<int>&rank , int x ,int y){
    x = find(x);
    y = find(y);
    if(x==y) return true;// cycle detected 
    if(rank[x]>=rank[y]){
        rank[x]++;
        parent[y]=x;
    }else {
        rank[y]++;
        parent[x]=y;
    }
    return false;
}

int main(){
    int m , n;
    cin>>m>>n;
    vector<int> parent(n+1);
    vector<int> rank(n+1,0);
    for(int i=0 ; i<n ;i++){
        parent[i]=i;
    }
    while(m--){
        string std; 
        if(str == "Union"){
            int x ,y ;
            bool isCycle= Union(parent, rank , x,y);
            if(isCycle){
                cout<<"Graph has cycle"<<endl;
            }
            else cout<<"Graph has no cycle"<<endl;
        }else{
            int x; 
            cin>>x;
            int par=find(parent,x);
            cout<<par<<endl;
        }
    }
}