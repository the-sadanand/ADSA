#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;

int Find(int a, vector<int> &parent){
    return parent[a]= parent[a]==a ? a : Find(parent[a], parent);
}

void Union(int x , int y , vector<int> &parent , vector<int> &rank){
    x = Find(x);
    y = Find(y);
    if(x==y) return ;
    if(rank[x]>rank[y]){
        rank[x]++;
        parent[y]=x;
    }
    else {
        parent[x]=y;
        rank[y]++;
    }
}

void display(){
    for(int i =0 ; i<graph.size() ; i++){
        cout<<i<<"->";
        for(auto node : graph[i]) {
           cout<<node<<" "; 
        }
        cout<<endl;
    }
}


int main(){
    int v , e;
    cin>>v>>e;
    graph.resize(v, list<int>());
    vector<int> parent(v) , rank(v,0);
    for(int i=0 ; i<v ; i++){
        parent[i]=i;
    }
    while(e--){
        int x , y;
        cin>>x>>y;
        Union(x,y,parent,rank);
    }
    unordered_set<int> totalparent ;
    for(int i=0 ; i<v ; i++){
        totalparent.insert(Find(i,parent));
    }
    cout<<totalparent.size();
}


// #include<bits/stdc++.h>
// using namespace std;

// int Find(int x, vector<int>& parent){
//     if(parent[x] == x) return x;
//     return parent[x] = Find(parent[x], parent);
// }

// void Union(int x, int y,
//            vector<int>& parent,
//            vector<int>& rank){

//     x = Find(x, parent);
//     y = Find(y, parent);

//     if(x == y) return;

//     if(rank[x] < rank[y]){
//         parent[x] = y;
//     }
//     else if(rank[x] > rank[y]){
//         parent[y] = x;
//     }
//     else{
//         parent[y] = x;
//         rank[x]++;
//     }
// }

// int main(){

//     int v,e;
//     cin >> v >> e;

//     vector<int> parent(v);
//     vector<int> rank(v,0);

//     for(int i=0;i<v;i++)
//         parent[i] = i;

//     while(e--){
//         int x,y;
//         cin >> x >> y;
//         Union(x,y,parent,rank);
//     }

//     unordered_set<int> components;

//     for(int i=0;i<v;i++){
//         components.insert(Find(i,parent));
//     }

//     cout << components.size();
// }