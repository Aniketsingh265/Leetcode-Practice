class Solution {
public:
    int deleteAndEarn(vector<int>& arr) {
        int maxVal = 0;
        for(int num : arr) maxVal = max(maxVal, num);
        
        vector<int> points(maxVal + 1, 0);
        for(int num : arr) {
            points[num] += num;
        }
        
        int takePrev = 0, skipPrev = 0;
        
        for(int i = 0; i <= maxVal; i++) {
            int currentTake = skipPrev + points[i]; 
            int currentSkip = max(skipPrev, takePrev); 
            
            skipPrev = currentSkip;
            takePrev = currentTake;
        }
        
        return max(skipPrev, takePrev);
    }
};