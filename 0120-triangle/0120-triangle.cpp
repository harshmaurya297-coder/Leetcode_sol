class Solution {
    int rec(int idx, int r, vector<vector<int>>& triangle, 
                            vector<vector<int>>& dp){

        if(r == 0)
            return triangle[0][0];

        if (idx < 0 || idx > r)
            return 1e9;

        if(dp[r][idx] != INT_MAX) 
            return dp[r][idx];

        int same = rec(idx, r - 1, triangle, dp);
        int next = rec(idx - 1, r - 1, triangle, dp);

        return dp[r][idx] = triangle[r][idx] + min(same, next);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[row - 1].size();
        int ans = INT_MAX;

        vector<vector<int>> dp(row);
        for (int i = 0; i < row; i++)
            dp[i] = vector<int>(i + 1, INT_MAX);

        for (int j = 0; j < row; j++) {
            ans = min(ans, rec(j, row - 1, triangle, dp));
        }

        return ans;
    }
};