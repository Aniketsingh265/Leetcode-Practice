class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& dp,
              vector<vector<int>>& arr) {
        if (i > m - 1 or j > n - 1) {
            return 0;
        }
        if (arr[i][j] == 1) {
            return 0;
        }
        if (i == m - 1 and j == n - 1 and arr[i][j] != -1) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int right = solve(i + 1, j, m, n, dp, arr);
        int down = solve(i, j + 1, m, n, dp, arr);

        return dp[i][j] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, dp, arr);
    }
};
