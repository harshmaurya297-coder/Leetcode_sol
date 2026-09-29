class Solution {
    bool f(int r, int c, int close, vector<vector<char>>& grid, vector<vector<vector<int>>>& dp){
        // base condition
        if(r < 0 || c < 0)
            return false;
        
        if(grid[r][c] == ')') close++;
        else close--;
        if(close < 0) return false;
        
        if(dp[r][c][close] != -1)
            return dp[r][c][close];

                                
        if(r == 0 && c == 0 ) return dp[r][c][close] = (close == 0);

        bool up = f(r - 1, c, close, grid, dp);
        bool left = f(r, c - 1, close, grid, dp);

        return dp[r][c][close] = (up || left);
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int path_length = row + col - 1;

        if (path_length % 2 != 0)
            return false;

        if (grid[0][0] == ')' ||
            grid[row - 1][col - 1] == '(')
            return false;

        vector<vector<vector<int>>> dp(row,vector<vector<int>>(col,vector<int>(path_length + 1, -1)));
        
        return f(row - 1, col - 1, 0, grid, dp);
    }
};