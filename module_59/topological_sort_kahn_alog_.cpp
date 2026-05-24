#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
int v ;
void add_edge(int a , int b,bool bir=true){
    graph[a].push_back(b);
    if(bir){
        // bidirectional hua to b ke index mai a
        graph[b].push_back(a);
    }
}

void topoBFS(){
    vector<int> indegree(v,0);// index number == node number 
    // value at each index is number or incoming edges 
    unordered_set<int> vis; // set for visited node  -> once who appear in queue
    queue<int> qu;
    for(int i =0 ; i<v ; i++){
        for(auto neighbour :graph[i]){
            // i-------> neighbour
            indegree[neighbour]++;
        }
    }
    for(int i =0 ; i<v; i++){
        if(indegree[i]==0) qu.push(indegree[i]);
        vis.insert(i);
    }
    while(not qu.empty()){
        int node=qu.front();
        cout<<node<<" ";
        qu.pop();
        for(auto neighbour:graph[node]){
         if(not vis.count(neighbour))   {
            indegree[neighbour]--;
            if(indegree[neighbour]==0) {
                qu.push(neighbour);
                vis.insert(neighbour);
            }
           }
        }     
    }
}
int main(){
    int e;
    cin>>v;
    cin>>e;
    graph.resize(v,list<int>());
    while(e--){
        int x , y;
        cin>>x>>y;
        add_edge(x,y,false);
    }
    topoBFS();
}