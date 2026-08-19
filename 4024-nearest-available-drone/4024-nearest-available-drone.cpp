class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        // finding the manhattan dostance.
        int index = -1;
        int minDistance = INT_MAX;
        for (int i = 0; i < drones.size(); i++) {
            int d = abs(drones[i][0] - target[0]) + abs(drones[i][1] - target[1]);
            if (d <= drones[i][2]) {
                if (d < minDistance) {
                    minDistance = d;
                    index = i;
                }
            }
        }
        return index;
    }
};