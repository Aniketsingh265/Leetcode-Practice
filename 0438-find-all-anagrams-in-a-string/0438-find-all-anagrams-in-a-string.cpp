class Solution {
public:

    vector<int> findAnagrams(string s, string p) {

        int n=s.size(),l=0,h=0,count=0;

        vector<int>mp(26,0);

        vector<int>result;

        for(int i=0;i<p.size();i++){
            int curr=p[i]-'a';
            mp[curr]++;
        }

        while(h<n){

            int curr=s[h]-'a';

            if(mp[curr]>0){
                count++;
            }

            mp[curr]--;

            if(count==p.size()){
                result.push_back(l);
            }

            if(h>=p.size()-1){
                int back=s[l]-'a';
                mp[back]++;
                if(mp[back]>0) count--;
                l++;
            }

            h++;
        }


        return result;

        
        
    }
};