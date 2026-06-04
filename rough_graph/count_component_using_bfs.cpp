#include<bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
void add_edge(int src ,int dest , bool bir=false){
    graph[src].push_back(dest);
    if(bir) graph[dest].push_back(src);
}
void bfs(int src , unordered_set<int> &vis, vector<list<int>>&graph){
    queue<int>qu ;
    qu.push(src);
    vis.insert(src);
    while(!qu.empty()){
        auto curr = qu.front();
        qu.pop();
        for(auto neigh:graph[curr]){
            if(!vis.count(neigh)){
                qu.push(neigh);
                vis.insert(neigh);
            }
        }
    }
}
int main(){
    int v , e;
    cin>> v>>e;
    graph.resize(v, list<int>());
    unordered_set<int> vis;
    while(e--){
        int a , b;
        cin>>a>>b;
        add_edge(a,b,fasle);
    }
    int component = 0;
    for(int i  =0 ; i<v ; i++){
        if(!vis.count(i)){
            bfs(i, vis,graph);
            component++;
        }
    }
    cout<<component;
}





// #include<bits/stdc++.h>
// using namespace std;

// vector<list<int>> graph;

// void add_edge(int src, int dest, bool bidir=false){
//     graph[src].push_back(dest);

//     if(bidir)
//         graph[dest].push_back(src);
// }

// void bfs(int src, unordered_set<int>& vis){

//     queue<int> q;

//     q.push(src);
//     vis.insert(src);

//     while(!q.empty()){

//         int curr = q.front();
//         q.pop();

//         for(auto neigh : graph[curr]){

//             if(!vis.count(neigh)){
//                 vis.insert(neigh);
//                 q.push(neigh);
//             }
//         }
//     }
// }

// int main(){

//     int v,e;
//     cin >> v >> e;

//     graph.resize(v);

//     while(e--){

//         int a,b;
//         cin >> a >> b;

//         add_edge(a,b,true);
//     }

//     unordered_set<int> vis;

//     int components = 0;

//     for(int i=0;i<v;i++){

//         if(!vis.count(i)){
//             bfs(i,vis);
//             components++;
//         }
//     }

//     cout << components;
// }