class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int we_need = 0, size = nums.size();
        for(auto it : nums) we_need += it;
        we_need -= x;

        if(we_need < 0) return -1;
        if(we_need == 0) return size;

        int l = 0,ans = -1;
        int windowSum = 0;
        for(int r = 0; r < size; r ++){
            windowSum += nums[r];

            while (windowSum > we_need) {
                windowSum -= nums[l];
                l++;
            }

            if (windowSum == we_need) {
                ans = max(ans, r - l + 1);
            }
        }
        return ans == -1 ? -1 : size - ans;
    }
};