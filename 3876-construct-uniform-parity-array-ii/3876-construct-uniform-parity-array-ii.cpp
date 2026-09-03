class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int even = 0, odd = 0, minimum = INT_MAX;
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] % 2 == 0)
                even++;
            else {
                minimum = min(minimum, nums1[i]);
                odd++;
            }
        }

        if (even == nums1.size() or odd == nums1.size())
            return true;
        for (auto x : nums1) {
            if (minimum > x)
                return false;
        }

        return true;
    }
};