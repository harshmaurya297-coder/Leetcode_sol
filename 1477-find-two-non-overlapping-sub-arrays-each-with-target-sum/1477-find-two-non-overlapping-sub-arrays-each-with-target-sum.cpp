class Solution {
    const int INF = 1e9;

    int ans = INF;
    int left = 0;
    long long sum = 0;
    void f(int right, vector<int>& arr, int target, vector<int>& dp) {
        if(right == arr.size())
            return;
        sum += arr[right];
        while(sum > target) {
            sum -= arr[left];
            left++;
        }
        if(sum == target) {
            int len = right - left + 1;
            if(left > 0 && dp[left - 1] != INF) {
                ans = min(ans, len + dp[left - 1]);
            }
            dp[right] = len;
        }
        // Carry forward the best previous subarray
        if(right > 0) {
            dp[right] = min(dp[right], dp[right - 1]);
        }
        f(right + 1, arr, target, dp);
    }

public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp(n, INF);
        f(0, arr, target, dp);
        return ans == INF ? -1 : ans;
    }
};