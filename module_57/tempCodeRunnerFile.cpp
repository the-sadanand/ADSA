int go(vector<vector<int>> &island, int i , int j,vector<int> path){
//     path.push_back(island[i][j]);
//     // fool[i][j]=true;
//     if((i<5 && j==0 ) || (i==0 && j<5) || (i<5 && j==4)|| (i==4 && j<5)) {
//         for(int ele:path) cout<<ele<<" ";
//         cout<<endl;
//         return -1;
//     }
//     // up
//     if( (i>0 && j>0) && island[i-1][j]<=island[i][j] && !fool[i][j] ){
//         go(island, i-1 , j,path);
        
//     }
//     // down
//     if( (i>0 && j>0) && island[i+1][j]<=island[i][j] && !fool[i][j] ){
//         go(island,i+1 ,j,path);
        
//     }
//     // left
//     if( (i>0 && j>0) && island[i][j-1]<=island[i][j] && !fool[i][j] ){
//         go(island,i,j-1,path);
        
//     }
//     // right
//     if( (i>0 && j>0) && island[i][j+1]<=island[i][j] && !fool[i][j] ){
//         go(island, i , j+1,path);
//     }
//     return -1;
// }