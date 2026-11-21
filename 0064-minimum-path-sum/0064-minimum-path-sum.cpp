class Solution {
    int rec(vector<vector<int>>& dp, int r, int c, vector<vector<int>>& grid){

        if(r == 0 && c == 0) return grid[0][0];

        if(dp[r][c] != -1) return dp[r][c];

        int up = INT_MAX, left = INT_MAX;

        if(r > 0)  up = grid[r][c] + rec(dp, r - 1, c, grid);
        if(c > 0)  left = grid[r][c] + rec(dp, r, c - 1, grid);

        return dp[r][c] = min(up, left);
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid [0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return rec(dp, m - 1, n - 1, grid);

    }
};