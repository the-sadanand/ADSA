#include<iostream>
#include<vector>
#include<queue>
#include<list> // provide built in linked list
#include<unordered_set>


using namespace std;
// a vector(with graph name) which store a linked list at every index 
vector<list<int>> graph;

int v ; // no of vertices

void add_edge(int src , int dest , bool bi_dir = true){
    graph[src].push_back(dest); // go to graph(src,a index in vector  and at that index add new vertex in its list list)

    // if graph is bi-directional then src is also needed to add in list that pointed or contained at dest index so , logic is :
    if(bi_dir){
        graph[dest].push_back(src);
    }

}


// display functions

void display(){
    for(int i =0  ; i < graph.size(); i++){
        cout<<i<<"->";
        for(auto el : graph[i]){
            cout<<el <<" , ";
        }
        cout<<endl;
    }
}
unordered_set<int>visited;
vector<vector<int>> result;
void bfs(int src , int dest , vector<int> &dist){
    queue<int> qu;
    visited.clear();
    dist.resize(v,INT_MAX);
    dist[src] =0;
    visited.insert(src);
    qu.push(src);
    while(not qu.empty()){
        int curr= qu.front();
        qu.pop();
        for(auto neighbour : graph[curr]){
            if(not visited.cout(neighbour)){
                qu.push(neighbour);
                visited.insert(neighbour);
                dist[neighbour]=dist[curr]+1;
            }
        }
    }
}

int main(){
    cout<<"Enter the number of vertices  ";
    cin>>v;
    visited.resize(v,false);
    graph.resize(v,list<int> ());
    int e;
    cout<<"Enter the number of Edges ";
    cin>>e;
    cout<<"Enter source vertex and destination vertex "<<endl;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d,false);
    }
    display();
    cout<<endl;
    vector<int> dist;
    bfs(3,0,dist);
    for(int i =0 ; i<dist.size() ; i++){
        cout<<dist[i]<<" ";
    }

    return 0;
}


