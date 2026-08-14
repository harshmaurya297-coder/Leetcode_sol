class Solution {
    int f(int idx , vector<int> nums, vector<int>& dp, int start){
        if (idx < start)
            return 0;

        if (idx == start)
            return nums[idx];

        if (dp[idx] != -1)
            return dp[idx];

        int taken = f(idx - 2, nums, dp, start) + nums[idx];
        int notaken = f(idx - 1, nums, dp, start);

        return dp[idx] = max(taken, notaken);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];
        vector<int> dp1(n, -1);
        int case1 = f(n - 2, nums, dp1, 0);

        vector<int> dp2(n, -1);
        int case2 = f(n - 1, nums, dp2, 1);
        return max(case1, case2);
    }
};