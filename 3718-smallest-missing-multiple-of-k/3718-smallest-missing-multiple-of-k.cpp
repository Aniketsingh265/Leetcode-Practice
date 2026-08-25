class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        set<int> st(nums.begin(), nums.end());
        int i = 1;
        while (true) {
            if (!st.count(k * i)) {
                return k * i;
            }
            i++;
        }
    }
};