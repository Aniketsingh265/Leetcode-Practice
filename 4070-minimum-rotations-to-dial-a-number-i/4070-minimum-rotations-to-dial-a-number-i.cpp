class Solution {
public:
    int minRotations(string s) {

        int ans=0;

        int dist1=abs(s.front()-'0');
        int r1=min(dist1,10-dist1);

        ans+=r1;
        
        for(int i=0;i<s.size()-1;i++){

            int dist=abs(s[i]-s[i+1]);
            int r=min(dist,10-dist);

            ans+=r;
        }

        return ans;
        
    }
};