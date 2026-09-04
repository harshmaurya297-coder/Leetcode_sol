#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,fma,sse4,popcnt,lzcnt,bmi,bmi2")

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if(n <= 1) return 0;
        int maxi = nums[0], mini = nums[n - 1];
        vector<int> mx, v;
        vector<int> mn(n);

        for(auto it : nums){
            if(it > maxi)
                maxi = it;
            mx.push_back(maxi);
        }
        mn[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            mn[i] = min(nums[i], mn[i + 1]);
        }

        if(mn[0] == mx[n - 1]) return 0;

        for (int i = 0; i < n; ++i) {
            int score = mx[i] - mn[i];
            if (score <= k) {
                return i;
            }
        }
        return -1;
    }
};