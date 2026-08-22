class Solution {
    public boolean checkDivisibility(int n) {
        int original = n;
        int sum = 0;
        int prod = 1;
        while(n!=0){
            int d = n%10;
            sum+=d;
            prod*=d;
            n=n/10;
        }
        int finalSum = sum+prod;
        if(original % finalSum == 0){
            return true;
        }
        return false;
    }
}