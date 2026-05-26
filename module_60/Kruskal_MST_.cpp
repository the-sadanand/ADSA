#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int Find(int a , vector<int> &parent){
    return parent[a]= parent[a]==a ? a : Find(parent[a],parent);
}

void Union(int a , int b , vector<int>&parent , vector<int> &rank){
    a = Find(a, parent);
    b = Find(b,parent);
    if(a==b) return ;
    if(rank[a]>=rank[b]){
        parent[b]=a;
        rank[a]++;
    }
    else {
        rank[b]++;
        parent[a]=b;
    }
}
struct Edge{
    int src;
    int dest;
    int wt;
};
bool cmp(Edge e1, Edge e2){
    return e1.wt < e2.wt;
}
ll Kruskals(vector<Edge>&input , int n , int e){
    sort(input.begin(),input.end(),cmp);
    vector<int>parent(n+1);
    vector<int>rank(n+1 , 1);
    for(int i =0 ; i<=n ; i++){
        parent[i]=i;
    }
    int countEdge =0 ; 
    int i =0 ;
    ll ans =0 ; 
    while(countEdge<n-1 && i < input.size()){
        Edge curr = input[i];
        int srcPar = Find(parent,curr.src);
        int destPar = Find(parent, curr.dest);
        if(srcPar != destPar){
            // include Edge as it will not make cycle
            Union(srcPar,destPar,parent,rank);
            ans+=curr.wt;
            countEdge++;
        }
        i++; // don't matter you picked last edge or not you have to go for next edge

    }
    return ans;
}
int main(){
    int n , e;
    cin>>n>>e;
    vector<Edge> v(e);
    for(int i = 0 ; i < e ; i++){
        cin>>v[i].src>>v[i].dest>>v[i].wt;
    }
    cout<<Kruskals(v,n,e)<<endl;
}