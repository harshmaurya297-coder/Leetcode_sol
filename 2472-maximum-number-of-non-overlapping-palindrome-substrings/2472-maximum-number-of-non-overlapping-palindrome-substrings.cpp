class Solution {
int solve(int idx, string &s, int k, vector<int>& dp, vector<vector<bool>>& pal) {

    if (idx < 0)
        return 0;

    if (dp[idx] != -1)
        return dp[idx];

    int ans = solve(idx - 1, s, k, dp, pal);

    for (int j = idx; j >= 0; j--) {
        if (idx - j + 1 >= k && pal[j][idx]) {
            ans = max(ans, 1 + solve(j - 1, s, k, dp, pal));
        }
    }
    return dp[idx] = ans;
}
public:
    int maxPalindromes(string s, int k) {
        vector<int> dp(s.size(), -1);
        vector<vector<bool>> pal(s.size(), vector<bool>(s.size(), false));
        int n = s.size();

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] &&
                    (j - i <= 1 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }
        return solve(s.size() - 1, s, k, dp, pal);
    }
};