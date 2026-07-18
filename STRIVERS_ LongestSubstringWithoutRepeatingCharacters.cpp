class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>count(256 , -1);
        int n = s.size();
        int left = 0;
        int right = 0;
        int max_length = 0;
        while(right < n){
            if(count[s[right]] != -1){
                if(count[s[right]] >= left){
                    left = count[s[right]]+1;
                }
            }
            int len = right-left+1;
            max_length = max(max_length , len);
            count[s[right]] = right;
            right++;
        }
        return max_length;
    }
};
