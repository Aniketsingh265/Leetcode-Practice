class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());

       int n = nums.size();
       set<vector<int>>st;

       for(int i = 0; i < n; i++){
            int start=i+1;
            int end=n-1;
            while(start<end){
                int sum = nums[i]+nums[start]+nums[end];
                if(sum==0){
                    st.insert({nums[i],nums[start],nums[end]});
                    start++;
                    end--;
                }
                else if(sum>0){
                    end--;
                }
                else{
                    start++;
                }
            }
       }
       vector<vector<int>>ans;
       for(auto x : st){
        ans.push_back(x);
       }
       return ans;
    }
};
