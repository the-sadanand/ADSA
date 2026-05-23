#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> direction{
    {-1,0},
    {1,0},
    {0,-1},
    {0,1}
};

void drawSquare(int n){
    for(int i=0 ; i<n;i++){
        for(int j=0 ; j<n ; j++){
            cout<<"[ ]"<<" ";
        }
        cout<<endl;
    }
}

void arrowDir(char dir){
    if(char=="up") cout<<"↑";
    if(char=="down") cout<<"→";
    if(char=="left") cout<<"←";
    if(char=="right") cout<<"→";
}

int main(){
    vector<vector<int>> Ocean={
        {1,2},
        {3,4}
    };
    for(int i=0 ; i<Ocean.size();i++){
        for(int j=0 ; j<Ocean[0].size() ;j++){
            if()
        }
    }
    drawSquare(5);
}