#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,fma,sse4,popcnt,lzcnt,bmi,bmi2")
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mn(n); // will store mini of i -> n
        mn[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--)
            mn[i] = min(mn[i + 1], nums[i]);
        
        int maxi = nums[0];
        for(int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]);
            if(maxi - mn[i] <= k) return i;
        }
        return -1;
    }
};
