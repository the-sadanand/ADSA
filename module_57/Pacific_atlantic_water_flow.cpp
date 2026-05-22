class Solution {
public:
    vector<vector<int>>direction{
        {-1, 0},//up
        { 1, 0},//down
        { 0,-1}, // left
        { 0, 1} // right
    };
    int rows;
    int cols;
    vector<vector<int>> h;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows=heights.size();
        cols=heights[0].size();
        h=heights;
        queue<pair<int,int>> pacificbfs;
        queue<pair<int,int>> atlanticbfs;
        for(int i =0 ; i<rows ; i++){
            pacificbfs.push({i,0});
            atlanticbfs.push({i,cols-1});
        } 
        for(int j=0 ; j<cols-1 ; j++){
            atlanticbfs.push({rows-1,j});
        }
        for(int j=1 ; j<cols ; j++){
            pacificbfs.push({0,j});
        }
        vector<vector<bool>>pacific = bfs(pacificbfs);
        vector<vector<bool>>atlantic = bfs(atlanticbfs);
        vector<vector<int>> result;
        for(int i =0 ; i< rows ; i++){
            for(int j=0 ; j<cols ; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    result.push_back({i,j});
                }
            }
        }

        return result;
    }

    vector<vector<bool>> bfs(queue<pair<int,int>> &qu){
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        while(!qu.empty()){
            auto cell= qu.front();
            int i = cell.first;
            int j = cell.second;
            qu.pop();
            visited[i][j]=true;
            for(int d=0 ; d<direction.size(); d++){
                int newRow = i + direction[d][0];
                int newCol = j + direction[d][1];
                if(newRow <0 || newCol<0 || newRow>=rows || newCol>=cols) continue;
                if(visited[newRow][newCol]) continue;
                if(h[newRow][newCol]<h[i][j]) continue;
                qu.push({newRow,newCol});
            }
        }
        return visited;
    }
};