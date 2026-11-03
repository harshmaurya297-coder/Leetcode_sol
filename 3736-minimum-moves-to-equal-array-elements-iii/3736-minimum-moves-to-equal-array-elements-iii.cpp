class Solution {
public:
    int minMoves(vector<int>& nums) {
        int to_be = *max_element(nums.begin(), nums.end());
        int ans = 0;

        for(int i = 0; i < nums.size(); i++){
            ans += to_be - nums[i];
        }
        return ans;
    }
};