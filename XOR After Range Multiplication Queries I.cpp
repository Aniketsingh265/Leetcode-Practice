class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=queries.size();
        int m=queries[0].size();
        int MOD=1e9+7;
        

        for(int i=0;i<n;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int k=queries[i][2];
            int v=queries[i][3];
            int idx=l;

            while(idx<=r){
                nums[idx] = (1LL*nums[idx]*v) %MOD;
                idx+=k;
            }
            
        }
        int a=nums[0];
        for(int i=1;i<nums.size();i++){
            a=a^nums[i];
        }
        return a;
    }
};
