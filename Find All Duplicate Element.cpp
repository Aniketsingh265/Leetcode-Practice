class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       int n=nums.size();
       unordered_map<int,int>map;
       for(int i=0;i<n;i++){
        map[nums[i]]++;
       } 
       vector<int>ans;
       for(auto x:map){
        if(x.second>=2){
            ans.push_back(x.first);
        }
       }
       return ans;
    }
};
