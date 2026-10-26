class Solution {
public:
int bfs(int x,int y,vector<vector<int>>&grid,vector<vector<int>>&visited,int k){
    visited[x][y]=1;
    long long count=0;
    queue<pair<int,int>>q;
    q.push({x,y});
    while(!q.empty()){
        int row=q.front().first;
        int column=q.front().second;
        q.pop();
         count=count+grid[row][column];
        if(row-1>=0 && visited[row-1][column]==0 && grid[row-1][column]>0){
            visited[row-1][column]=1;
            q.push({row-1, column});
        }

        if(row+1<grid.size() && visited[row+1][column]==0 && grid[row+1][column]>0){
            visited[row+1][column]=1;
            q.push({row+1, column});
        }
        if(column-1>=0 && visited[row][column-1]==0 && grid[row][column-1]>0){
            visited[row][column-1]=1;
            q.push({row,column-1});
        }
        if(column+1<grid[0].size() && visited[row][column+1]==0 && grid[row][column+1]>0){
            visited[row][column+1]=1;
            q.push({row,column+1});
        }
    }
    if(count%k==0){
        return 1;
    }
    else{
        return 0;
    }

}

    int countIslands(vector<vector<int>>& grid, int k) {
       vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
       int res=0;
       for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]!=0 and !visited[i][j]){
                res=res+bfs(i,j,grid,visited,k);
            }
        }
       } 
       return res;
    }
};