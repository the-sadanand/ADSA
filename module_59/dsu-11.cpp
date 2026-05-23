// codeforces 

#include<iostream>
#include<vector>

using namespace std;
int find(vector<int> &parent , int a){
    return  parent[a]=parent[a]==a ? a:find(parent,parent[a]);
}


void union(vector<int>&parent , vector<int>&sz , vector<int> &rank , vector<int>&minimal , vector<int>&maximal , int a , int b){
    a = find(a);
    b = find(b);
    if(a==b) return ;
    if(rank[a]>rank[b]){
        rank[a]++;
        parent[b]=a;
        maximal[a]=max(maximal[a],maximal[b]);
        minimal[b]=max(minimal[b],minimal[b]);
        sz[a]+=sz[b];
    }
    else{
        rank[b]++;
        parent[a]=b;
        maximal[b]=max(maximal[a],maximal[b]);
        minimal[a]=min(minimal[a],minimal[b]);
        sz[b]+=sz[a];
    }
}


void file_i_o(){
    ios_base::sync_with_studio(0);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    int n,m;
    // n -> number of entries m -> number of cases
    cin>>m>>n;
    vector<int>parent(n+1);
    vector<int>rank(n+1,0);
    vector<int>sz(n+1,1);
    vector<int>minimal(n+1);
    vector<int>maximal(n+1);
    for(int i=0 ; i< n ;i++){
        parent[i]=minimal[i]=maximal[i]=i;
    }

    while(m--){
        string str;
        cin>>str;
        if(str =="union"){
            int x, y;
            cin>>x>>y;
            union(parent , sz , rank , minimal , maximal , x , y);
        }
        else{
            int x;
            cin>>x;
            x=find(parent,x);
            cout<<minimal[x]<<" "<<maximal[x]<<" "<<sz[x]<<"\n";
        }
    }
}