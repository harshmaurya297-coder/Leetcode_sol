class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];

        int ans = 0;
        
        return accumulate(nums.begin(), nums.end(), 0,
            [median](int sum, int x) {
                return sum + abs(x - median);
            }
        );
    }
};