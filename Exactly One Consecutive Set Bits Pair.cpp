class Solution {
public:
    string convertToBinary(int n) {
        string bin = "";
        if(n==0){
            return "0";
        }
        while (n) {
            bin = char(n % 2 + '0') + bin;
            n = n / 2;
        }
        return bin;
    }

    bool consecutiveSetBits(int n) {
        // cout<<convertToBinary(n);
        // return true;
        string toBinary = convertToBinary(n);
        int count = 0;
        for (int i = 0; i < toBinary.size() - 1; i++) {
            if (toBinary[i] == '1' && toBinary[i + 1] == '1') {
                count++;
            }
        }
        if (count == 1) {
            return true;
        }
        return false;
    }
};
