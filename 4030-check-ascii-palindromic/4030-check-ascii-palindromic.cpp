class Solution {
public:
    // fun to find the binary rep of any number.
    string Binary(int n) {
        string str = "";
        while(n) {
            int r = n % 2;
            str += to_string(r);
            n = n / 2;
        }
        reverse(str.begin(), str.end());
        while(str.size() < 8) { // 8 bit binary representation.
            str.insert(0, "0");
        }
        return str;
    }

    bool isPalindromic(string s) {
        string str = "";
        for(int i = 0; i < s.size(); i++) {
            int ascii = int(s[i]);
            string str2 = Binary(ascii);
            str += str2;
        }
        string ans = str;
        reverse(ans.begin(), ans.end()); // reverse of the existing string to check pa;indrome.

        if(str == ans){
            return true;
        }
        return false;
    }
};