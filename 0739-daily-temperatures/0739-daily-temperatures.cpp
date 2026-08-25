class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        // vector<int>res(n,0);
        // for(int i = 0;i<n;i++){
        //     for(int j =i+1;j<n;j++){
        //         if(nums[i]<nums[j]){
        //             res[i]=j-i;
        //             break;
        //         }
        //     }
        // }
        // return res;
        vector<int>res(n);
        stack<int>st;
        for(int i = n-1 ;i>=0;i--){
            while(st.size()!=0 && nums[i] >= nums[st.top()]){
                st.pop();
            }
            if(st.size() ==0){
                res[i] = 0;
            }
            else{
                res[i] = st.top() - i; // number of total days (== j-i)
            }
            st.push(i);
        }
        return res;
    }
};