#include<bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
int v;
void add_edge(int src , int dest, bool dir=true){
    graph[src].push_back(dest);
    if(dir) graph[dest].push_back(src);
}

bool dfs(int src ,int parent , unordered_set<int> &vis){
    vis.insert(src);
    for(auto neighbour : graph[src]){
        if(vis.count(neighbour) && neighbour!=parent){
            // cycle detected
            return true;
        }
        if(!vis.count(neighbour)) {
            bool res = dfs(neighbour,src,vis);
            if(res==true) return true;
        }
    }
    return false;
}
bool has_cycle(){
    unordered_set<int> vis;
    for(int i = 0 ; i<v ; i++){
       if(!vis.count(i)) { 
         bool  result = dfs(i,-1 , vis);
        if(result) return true;
       }
       
    }
    return false;
}
void display(){
    int n =graph.size();
    for(int  i =0 ; i<n ;i++){
        cout<<i<<"->";
        for(auto el: graph[i]){
            cout<<el<<",";
        }
    }
}
int main(){
    cin>>v;
    graph.resize(v , list<int>());
    int e;
    cin>>e;
    while(e--){
        int s ,d;
        cin>>s>>d;
        add_edge(s,d, false);
    }
    display();
    cout<<endl;
    cout<<has_cycle();
}