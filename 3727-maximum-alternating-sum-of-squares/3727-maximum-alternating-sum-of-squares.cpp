class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++)
            nums[i] *= nums[i];

        long long ans = 0;

        ranges::sort(nums); //sort(nums.begin(), nums.end());  // similar as ranges

        return -accumulate(nums.begin(), nums.begin() + n/2,0LL)
               +accumulate(nums.begin() + n/2, nums.end(),0LL);
    }
};