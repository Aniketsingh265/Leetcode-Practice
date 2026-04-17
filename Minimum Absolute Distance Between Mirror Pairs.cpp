class Solution {
public:
    int reverse(int n){
        int num=0;
        while(n){
            int rem = n%10;
            num=num*10+rem;
            n=n/10;
        }
        return num;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int ans=INT_MAX;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                ans=min(ans,abs(i-mp[nums[i]]));
            }
            int val= reverse(nums[i]);
            mp[val]=i;
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};
