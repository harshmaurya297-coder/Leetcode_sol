class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        ranges::sort(nums);
        int ans = 1, len = 1;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1]) continue;
            else if(nums[i] == nums[i - 1] + 1) len++;
            else len = 1;

            ans = max(ans, len);
        }
        return ans;
    }
};