#include<bits/stdc++.h>
using namespace std;
graph<list<int>> graph;

void add_edge(int src ,int dest , bool bir = false){
    graph[src].push_back(dest);
    if(bir) graph[dest].push_back(src);
}

void dfs(int src , unordered_set<int> &vis){
    vis.insert(src);
    for(auto neigh : graph[src]){
        if(!vis.count(neigh)){
            dfs(neigh,vis);
        }
    }
}

int main(){
    int n , e;
    cin>>n>>e;
    graph.resize(n,list<int>());
    unordered_set<int> vis;
    while(e--){
        int a , b;
        cin>>a>>b;
        add_edge(a,b, false);
    }

    int component =0 ;
    for(int i=0 ; i< v ; i++){
        if(!vis.count(i)){
            dfs(i, vis);
            component++;
        }
    }
    return component;

}