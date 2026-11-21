// tabulation format

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid [0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if (r == 0 && c == 0) {
                    dp[r][c] = grid[0][0];
                } else {
                    int up = (r > 0) ? dp[r - 1][c] : INT_MAX;
                    int left = (c > 0) ? dp[r][c - 1] : INT_MAX;
                    dp[r][c] = grid[r][c] + min(up, left);
                }
            }
        }
        return dp[m - 1][n - 1];

    }
};