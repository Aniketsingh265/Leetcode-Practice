class Solution {
public:
    bool isValid(int l , int r , string &s , vector<vector<int>>&dp1){
        string temp = s.substr(l,r-l+1);

        if(dp1[l][r] != -1){
            return dp1[l][r];
        }

        if(temp.size() > 2){
            return dp1[l][r] = false;
        }

        if(temp[0] == '0'){
            return dp1[l][r] = false;
        }

        int num = stoi(temp);
        if(num >= 1 and num <= 26){
            return dp1[l][r] = true;
        }
        return dp1[l][r] = false;
    }
    int solve(int idx , string s , vector<int> &dp , vector<vector<int>> &dp1){
        if(idx>=s.size()){
            return 1;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int ans =0;
        for(int i = idx ;i<s.size();i++){
            if(isValid(idx,i,s ,dp1)){
                ans += solve(i+1 ,s,dp , dp1);
            }
        }
        return dp[idx] = ans;
    }
    int numDecodings(string s) {
        if(s.front() == '0'){
            return 0;
        }
        vector<int>dp(s.size() ,-1);
        vector<vector<int>>dp1(s.size() , vector<int>(s.size(),-1));
        return solve(0 ,s,dp ,dp1);
    }
};
