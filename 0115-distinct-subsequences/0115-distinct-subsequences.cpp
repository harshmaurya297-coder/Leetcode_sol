#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,fma,sse4,popcnt,lzcnt,bmi,bmi2")

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.size();
        const long long LIMIT = INT_MAX;

        vector<long long> dp(m + 1, 0);
        dp[0] = 1;

        for (char c : s) {
            for (int j = m; j >= 1; --j) {
                if (c == t[j - 1]) {
                    dp[j] = min(LIMIT, dp[j] + dp[j - 1]);
                }
            }
        }

        return (int)dp[m];
    }
};