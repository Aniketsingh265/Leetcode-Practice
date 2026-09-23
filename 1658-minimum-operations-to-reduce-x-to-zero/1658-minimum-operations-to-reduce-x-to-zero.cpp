/*
submited by AnshBh
*/
class Solution {
public:

    int minOperations(vector<int>& nums, int x) {
       int n=nums.size();

       unordered_map<int,int>aakansh,aman;

       int s1=0,s2=0;

       for(int i=0;i<nums.size();i++){
        s1+=nums[i];
        aakansh[s1]=i+1;
       }

       for(int i=n-1;i>=0;i--){
        s2+=nums[i];
        aman[s2]=n-i;
       }

       int mac=INT_MAX;

       if(aakansh.count(x)) mac=min(mac,aakansh[x]); 
       if(aman.count(x)) mac=min(mac,aman[x]);

       int sum=0;

       for(int i=0;i<n;i++){

        sum+=nums[i];

        if(aman.count(x-sum) and n-(i+1)>=aman[x-sum]){
            mac=min(mac,i+1+aman[x-sum]);
        }
       } 

       return mac==INT_MAX?-1:mac;
    }
};