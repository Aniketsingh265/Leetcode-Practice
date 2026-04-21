class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            int flag = 1;
            while (st.size() != 0 and st.top() > 0 and nums[i] < 0) {
                if (st.top() < abs(nums[i])) {
                    st.pop();
                } else if (st.top() == abs(nums[i])) {
                    st.pop();
                    flag = 0;
                    break;
                } else {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) {
                st.push(nums[i]);
            }
        }
        vector<int> ans;
        while (!st.empty()) {
            int top = st.top();
            ans.push_back(top);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
