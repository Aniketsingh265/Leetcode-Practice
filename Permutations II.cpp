class Solution {
public:
    set<vector<int>> st;
    void getUniquePermutations(vector<int>& nums, int index) {
        if (index == nums.size()) {
            st.insert(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            getUniquePermutations(nums, index + 1);
            swap(nums[index], nums[i]); // backtrack
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        getUniquePermutations(nums, 0);
        for (auto x : st) {
            ans.push_back({x});
        }
        return ans;
    }
};
