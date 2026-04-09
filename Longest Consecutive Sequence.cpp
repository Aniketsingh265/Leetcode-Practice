class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // unordered_set<int>st(nums.begin(),nums.end());

        int n=nums.size();
        if(n==0){
            return 0;
        }
        sort(nums.begin(),nums.end());

        int count=1;
        int ans=1;

        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
            else if(nums[i]==nums[i-1]+1){
                count++;
            }
            else{
                count=1;
            }

            ans = max(ans,count);
        }
        return ans;
    }
};
