class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        int size=nums.size()/2;
        for(int i=0;i<size;i++){
            sum=sum-nums[i]*nums[i];
        }
        for(int i=size;i<nums.size();i++){
            sum=sum+nums[i]*nums[i];
        }
        return sum;
       
    }
};