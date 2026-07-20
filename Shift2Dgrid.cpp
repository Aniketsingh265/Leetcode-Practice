class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int>arr;
        int m = grid.size();
        int n = grid[0].size();
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                arr.push_back(grid[i][j]);
            }
        }
        deque<int>dq(arr.begin() ,arr.end());
        while(k){
            int l = dq.back();
            dq.pop_back();
            dq.push_front(l);
            k--;
        }
        for(int i =0;i<m;i++){
            for(int j =0 ;j<n;j++){
                grid[i][j] = dq.front();
                dq.pop_front();
            }
        }
        return grid;
    }
};
