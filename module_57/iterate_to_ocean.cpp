#include<iostream>
#include<vector>
using namespace std ;

int go(vector<vector<int>> &island, int i , int j,vector<int> path,vector<vector<bool>>&fool){
    path.push_back(island[i][j]);
    fool[i][j]=true;
  
    if((i<5 && j==0 ) || (i==0 && j<5) || (i<5 && j==4)|| (i==4 && j<5)) {
        for(int ele:path) cout<<ele<<" ";
        fool[i][j]=true;
        cout<<endl;
        return -1;
    }
    // up
    if( (i>0 && j>0) && island[i-1][j]<=island[i][j] && !fool[i-1][j] ){
        go(island, i-1 , j,path,fool);
          
    }
    
    // down
    if( (i>0 && j>0) && island[i+1][j]<=island[i][j] && !fool[i+1][j] ){
        go(island,i+1 ,j,path,fool);
          
    }
     
    // left
    if( (i>0 && j>0) && island[i][j-1]<=island[i][j] && !fool[i][j-1] ){
        go(island,i,j-1,path,fool);
         
    }
     
    // right
    if( (i>0 && j>0) && island[i][j+1]<=island[i][j] && !fool[i][j+1] ){
        go(island, i , j+1,path,fool);
        
    }
    return -1;
}

int main(){
    vector<vector<int>>island{
        {11,4,7, 1, 9},
        {6,2,8 ,2 ,7 },
        {0,1,1, 3, 7},
        {11,9,11,6, 8},
        {3,4,8,  5 , 10},
    };  
    
    vector<vector<int>> chota{
        {3,3,3},
        {4,4,4},
        {3,3,3},
    };
    vector<vector<bool>> fool(5, vector<bool>(5, false));
    vector<int> path;         
    go(island,3,3,path,fool);
    return 0;
}