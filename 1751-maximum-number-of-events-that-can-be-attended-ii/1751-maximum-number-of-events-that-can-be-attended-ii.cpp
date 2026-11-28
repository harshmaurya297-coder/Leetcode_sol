class Solution {
private:
    int dfs(int r, vector<vector<int>>& events, int k, vector<vector<int>>& dp, vector<int>& starts){
        int n = events.size();

        if(r >= n || k == 0) return 0;
        if(dp[r][k] != -1) return dp[r][k];

        int pick = 0, notPick = 0;

        // not pick
        notPick = dfs(r + 1, events, k, dp, starts);


        // uper bound -> finds just smaller number idx
        int upper_bound_idx = upper_bound(starts.begin(), starts.end(), events[r] [1]) - starts.begin();

        // pick
        pick = events[r][2] +
                   dfs(upper_bound_idx, events, k - 1, dp, starts);


        return dp[r][k] = max(pick, notPick);
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());
        // Store starting days
        vector<int> starts;
        for (auto& e : events) {
            starts.push_back(e[0]);
        }
        vector<vector<int>> dp(n, vector<int> (k + 1, -1));

        return dfs(0, events, k, dp, starts);
    }
};