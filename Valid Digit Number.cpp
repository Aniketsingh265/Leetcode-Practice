class Solution {
public:
    vector<int> digits(int num){
        vector<int>ans;
        while(num){
            int d = num%10;
            ans.push_back(d);
            num=num/10;
        }
        return ans;
    }
    bool validDigit(int n, int x) {
        vector<int>res= digits(n);
        reverse(res.begin(),res.end()); // since, vector stores the digits from the backword.
        for(int i=0;i<res.size();i++){
            if(res[0]  == x)
                return false;
            if(res[i]==x){
                return true;
            }
        }
        return false;
    }
};
