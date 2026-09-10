class Solution {
    int f(int m, int n, vector<vector<int>>& dp, vector<vector<int>>& grid){
        if(m == 0 && n == 0 ) 
            return 1;
        if(m < 0 || n < 0 || grid[m][n] == 1) return 0;
        if(dp[m][n] != -1) return dp[m][n];

        int up = f(m, n - 1, dp, grid);
        int left = f(m - 1, n, dp, grid);
        return dp[m][n] = up + left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1)
            return 0;
        vector<vector<int>> dp(m, vector<int> (n, -1));

        return f(m - 1, n - 1, dp, obstacleGrid);
    }
};