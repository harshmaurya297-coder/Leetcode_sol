class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = 1e9;
        vector<int> dp(amount + 1, -1);
        
        auto solve = [&](auto&& self, int amt) -> int {
            if(amt == 0)
                return 0;

            if(amt < 0)
                return INF;
            
            if(dp[amt] != -1) 
                return dp[amt];

            int mini = INF;
            for(int coin : coins) {
                int ans = self(self, amt - coin);
                mini = min(mini, 1 + ans);
            }

            return dp[amt] = mini;
        };

        int ans = solve(solve, amount);

        return ans == INF ? -1 : ans;
    }
};