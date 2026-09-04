class Solution {
public:
    int firstStableIndex(vector<int>& arr, int k) {
        int res = INT_MAX;

        for (int i = 0; i < arr.size(); i++) {
            int val1 = INT_MIN, val2 = INT_MAX;
            for (int j = 0; j <= i; j++) {
                val1 = max(val1, arr[j]);
            }
            for (int j = i; j < arr.size(); j++) {
                val2 = min(val2, arr[j]);
            }
            int ans = val1 - val2;
            if (ans <= k) {
                res = min(res, i);
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};