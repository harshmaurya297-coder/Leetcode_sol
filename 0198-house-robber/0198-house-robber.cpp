class Solution {
    int profit(int idx, vector<int>& nums, vector<int>& dp) {
        if(idx == 0) return nums[0];
        if(idx < 0) return 0;

        if (dp[idx] != -1) return dp[idx];

        int notTake = profit(idx - 1, nums, dp);
        int take = profit(idx - 2, nums, dp) + nums[idx];

        return dp[idx] = max(take, notTake);
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return profit(nums.size() - 1, nums, dp);
    }
};