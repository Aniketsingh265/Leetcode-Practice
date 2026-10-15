class Solution {
public:
    int solve(int idx, int t, vector<int>& arr, vector<vector<int>>&dp){
        if(idx == arr.size()) return 0;
        if(dp[idx][t] != -1) return dp[idx][t];

        int take = INT_MIN; 
        int skip = INT_MIN;

        take = arr[idx]*t + solve(idx+1, t+1, arr, dp);
        skip = solve(idx+1, t, arr, dp);

        return dp[idx][t] = max(take,skip);
    }

    int maxSatisfaction(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        int ans = solve(0,1,arr,dp);
        return ans;
    }
};