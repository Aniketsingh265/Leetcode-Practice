class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>s(nums.begin(),nums.end());

        int a = 1;
        int b = k*a;

        for(int i : s){
            if(s.find(b)!=s.end()){
                a++;
                b = k*a;
            }
            else{
                return b;
            }
        }
        a++;
        return b;
    }
};