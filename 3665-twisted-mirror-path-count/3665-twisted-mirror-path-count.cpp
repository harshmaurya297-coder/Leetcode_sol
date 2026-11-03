class Solution {
    const int MOD = 1e9 + 7;

    int rec(int i, int j, int dir, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        int m = grid.size();
        int n = grid[0].size();

        if(i >= m || j >= n) return 0;

        if(i == m-1 && j == n-1)
            return 1;

        if(dp[i][j][dir] != -1) 
            return dp[i][j][dir];

        int path = 0;

        // path having mirror
        if(grid[i][j] == 1){
            //up
            if(dir == 0){
                path = rec(i + 1, j, 1, grid, dp) % MOD;
            }// down
            else{
                path = rec(i, j + 1, 0, grid, dp) % MOD;
            }
        }// no mirror path
        else {
            path = (rec(i, j + 1, 0, grid, dp)
              + rec(i + 1, j, 1, grid, dp)) % MOD;
        }
        

        return dp[i][j][dir] = path;
    }
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if(m == 1 && n == 1)
            return 1;

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>> (
            n, vector<int> (2, -1)
            )
        );
        
        int ans = 0;

        if(n > 1)
            ans = (ans + rec(0, 1, 0, grid, dp)) % MOD;

        if(m > 1)
            ans = (ans + rec(1, 0, 1, grid, dp)) % MOD;

        return ans;
    }
};