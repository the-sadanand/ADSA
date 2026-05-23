#include<iostream>
#include<vector>
using namespace std;

class DSU{
    vector<int> parent;
    vector<int> size;
public:
    DSU(int n){
        parent.resize(n);
        size.resize(n);
        for(int i=0 ; i<n ; i++){               
            parent[i]=i;
            size[i]=1;
        }
    }           
    int find(int u){
        if(parent[u]==u) return u;
        return parent[u]=find(parent[u]);
    }
    void unionBySize(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv) return;
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};          
int main(){
    DSU dsu(5);
    dsu.unionBySize(0,1);
    dsu.unionBySize(1,2);
    cout<<dsu.find(0)<<endl;
    cout<<dsu.find(1)<<endl;
    cout<<dsu.find(2)<<endl;
    cout<<dsu.find(3)<<endl;
    cout<<dsu.find(4)<<endl;
}   