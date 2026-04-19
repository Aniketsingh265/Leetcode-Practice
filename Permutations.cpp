class Solution {
public:
    void getPermutations(vector<int>&nums , int index , vector<vector<int>> &ans){
        if(index == nums.size()){
            ans.push_back({nums});
            return;
        }

        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]); // swap index Place => ith element choice 
            getPermutations(nums , index+1 , ans);
            swap(nums[index],nums[i]); // Backtrack
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getPermutations(nums,0,ans);
        return ans;
    }
};
