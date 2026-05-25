#include<bits/stdc++.h>
using namespace std;
int v;
vector<list<int> > graph;

void add_edge(int src , int dest , bool dir=true){
    graph[src].push_back(dest);
    if(dir) graph[dest].push_back(src);
}

void display(){
    for(int i = 0 ; i<graph.size(); i++){
        count<<i<<"->";
        for(auto ele:graph[i]){
            cout<<ele<<",";
        }

    }
}

bool bfs(int src){
    unordered_set<int>vis;
    vector<int> parent(v,-1);
    queue<int> qu;
    queue.push(src);
    vis.insert(src);
    while(!qu.empty()){
        int curr = qu.front();
        qu.pop();
        for(auto neighbour : graph[curr]){
            if(vis.count(neighbour) && neighbour!=parent[curr]) return true;
            if(!vis.count(neighbour)) {
             vis.insert(neighbour);
             parent[neighbour]=curr;
             qu.push(neighbour);   
            }
        }
    }
    return false;
}
bool has_cycle(){
    unordered_set<int> vis;
    for(int i =0 ; i<v ;i++){
        if(!vis.count(i)){
            bool res = bfs(i);
            if(result==true) return true;
        }
    }
    return false;
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