#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<unordered_map<int,int>> graph;
int v;// no of vetices

void add_edge(int src , int dest ,int wt, bool bi_dir= true){
    graph[src][dest]=wt; // go to src (index in graph ) add there dest wiht weight (wt) src -> {dest ,wt}->{dest2 , wt2}

    if(bi_dir){
        graph[dest][src]=wt;
    }

}

void display(){
     for(int i =0  ; i < graph.size(); i++){
        cout<<i<<"->";
        for(auto el : graph[i]){
            cout<<"{ "<<el.first <<"  "<<el.second<<" } , ";
        }
        cout<<endl;
    }
}

int main(){
    cout<<" Enter Number of vertices "<<endl;
    cin>>v;
    graph.resize(v, unordered_map<int,int> ());
    int e ;
    cout<<" Enter Number of Edges "<<endl;
    cin>>e;
    cout<<" Enter source destination and weight till number of edges consumed "<<endl;
    while(e--){

        int s , d, wt;
        cin>>s>>d>>wt;
        add_edge(s,d,wt);
    }
    display();
    return 0;
}