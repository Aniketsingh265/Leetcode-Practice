class Solution {
public:
    typedef long long ll;
    long long countCommas(long long n) {
        ll res = 0;
        ll start = 1000;
        int commas = 1;

        while (start <= n) {
            ll end = start * 1000 - 1;
            if (end > n)
                end = n;

            res += (end - start + 1) * commas;

            start *= 1000;
            commas++;
        }

        return res;
    }
};