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

int main(){
    cin>>v;
    graph.resize(v,list<int> ());
    int e;
    cin>>e;
    while(e--){
        int s , d;
        cin>>s>>d;
        add_edge(s,d,false);
    }
    display();
    return 0;
}


