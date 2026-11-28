class Solution {
    int dfs(int idx ,vector<int>& dp, vector<array<int, 3>> &jobs){
        int n = jobs.size();

        // base condition
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];

        int pick = 0, notPick = 0;
        // not pick 
        notPick = dfs(idx + 1, dp, jobs);

        // pick 
        int next_idx = lower_bound(
            jobs.begin() + idx + 1,
            jobs.end(),
            array<int, 3>{jobs[idx][1], INT_MIN, INT_MIN},
            [](const auto& a, const auto& b) {
                return a[0] < b[0];
            }
        ) - jobs.begin();
        pick = jobs[idx][2] + dfs(next_idx, dp, jobs);

        return dp[idx] = max(pick, notPick);
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        vector<int> dp(n, -1);
        vector<array<int, 3>> jobs;

        for(int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());

        
        return dfs(0, dp, jobs);
    }
};