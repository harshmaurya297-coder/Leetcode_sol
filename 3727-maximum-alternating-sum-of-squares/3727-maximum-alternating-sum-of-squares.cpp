class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
            nums[i] *= nums[i];

        long long ans = 0;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++)
            if(i < nums.size()/2)
                ans -= nums[i];
            else
                ans += nums[i];

        return ans;
    }
};