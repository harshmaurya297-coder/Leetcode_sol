class Solution {

public:
    int largestInteger(vector<int>& nums, int k) {

        int n = nums.size();

        map<int, int> mp;

        for (int x : nums)
            mp[x]++;

        int ans = -1;
        // Case 1: k == 1 
        if (k == 1) {
            for (auto it : mp) {
                if (it.second == 1) {
                    ans = max(ans, it.first);
                }
            }
            return ans;
        }

        // Case 2: k == n
        if (k == n) {
            for (auto it : mp) {
                ans = max(ans, it.first);
            }
            return ans;
        }

        // Case 3: 1 < k < n
        if (mp[nums[0]] == 1)
            ans = max(ans, nums[0]);

        if (mp[nums[n - 1]] == 1)
            ans = max(ans, nums[n - 1]);

        return ans;
    }
};