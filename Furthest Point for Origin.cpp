class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int s = count(moves.begin(), moves.end(), 'L');
        int t = count(moves.begin(), moves.end(), 'R');
        int distance = 0;

        for (char i : moves) {
            if (i == 'L') {
                distance--;
            } else if (i == 'R') {
                distance++;
            } else if (s > t) {
                distance--;
            } else if (t > s) {
                distance++;
            } else if (t == s) {
                distance++;
            }
        }

        return abs(distance);
    }
};
