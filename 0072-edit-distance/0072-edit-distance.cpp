class Solution {
public:
    int m , n;

    int solve(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){
        //base case
        if(i >= m){
            return n-j;
        }

        if(j >= n){
            return m-i;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]){
            return dp[i][j] = solve(i+1,j+1,word1,word2, dp);
        }

        int ins = INT_MAX, del = INT_MAX, rep = INT_MAX;

        ins = 1+solve(i,j+1,word1,word2,dp);
        del = 1+solve(i+1,j,word1,word2,dp);
        rep = 1+solve(i+1,j+1,word1,word2,dp);

        return dp[i][j] = min({ins,del,rep});
    }

    int minDistance(string word1, string word2) {
        m = word1.size();
        n = word2.size();

        vector<vector<int>> dp(m,vector<int>(n,-1));

        return solve(0, 0, word1, word2, dp);
        // return solve(0, 0, word1, word2);
    }
};