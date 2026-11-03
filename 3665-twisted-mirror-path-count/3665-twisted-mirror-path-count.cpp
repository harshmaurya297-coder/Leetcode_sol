class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        // dp will represent no of path crossing idx
        vector<int> dp(n, 0);
        dp[0] = 1;

        for(int i = 0; i < m; i++){
            int left = 0;
            for(int j = 0; j < n; j++){
                int up = dp[j];

                // mirror hai
                if(grid[i][j] == 1){
                    dp[j] = left;
                    left = up;
                }
                else {
                    int ways = (up + left) % MOD;

                    dp[j] = ways;
                    left = ways;
                }


            }
        }

        return dp[n - 1];
    }
};