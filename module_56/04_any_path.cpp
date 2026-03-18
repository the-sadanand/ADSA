#include<iostream>
#include<vector>
#include<list> // provide built in linked list

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
// implement the logic of is path exsist between given two vertices
vector<bool>visited;  

// OLD BUGGY FUNCTION - COMMENTED OUT
// This function had a flaw: it would return false even if a path existed
// because it only checked immediate neighbors without proper backtracking
/*
bool isPath(int src , int dest ){
    if(src==dest) return true;
    if(visited[src]==false){
        visited[src]=true;
        for(auto ele:graph[src]){
            if(isPath(ele,dest)) return true;
        }
    }
    return false;
}
*/

// ROBUST isPath FUNCTION
// Uses DFS to find if a path exists from src to dest
// Properly handles visited nodes and returns only when path is actually found
bool isPath(int src , int dest ){
    // Base case: if source is the destination
    if(src == dest) return true;
    
    // Mark current node as visited
    visited[src] = true;
    
    // Explore all neighbors of src
    for(auto neighbor : graph[src]){
        // Only explore unvisited neighbors
        if(!visited[neighbor]){
            // If path found through this neighbor, return true
            if(isPath(neighbor, dest)){
                return true;
            }
        }
    }
    
    // No path found from src to dest
    return false;
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
    cout<<isPath(0,1);
    return 0;
}


