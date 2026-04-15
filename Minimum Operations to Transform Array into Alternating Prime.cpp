class Solution {
public:
    bool isPrime(int n){
        if(n<=1){
            return false;
        }
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }

    int nextPrime(int n){
        while(!isPrime(n)){
            n++;
        }
        return n;
    }

    int nextNonPrime(int n){
        while(isPrime(n)){
            n++;
        }
        return n;
    }

    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        
        for(int i=0;i<n;i++){
            if(i%2==0){
                while(!isPrime(nums[i])){
                    int a = nextPrime(nums[i]);
                    count+=(a-nums[i]);
                    break; 
                }
            }
            else{
                while(isPrime(nums[i])){
                    int a = nextNonPrime(nums[i]);
                    count+=(a-nums[i]);
                    break;
                }
            }
        }
        return count;
    }
};
