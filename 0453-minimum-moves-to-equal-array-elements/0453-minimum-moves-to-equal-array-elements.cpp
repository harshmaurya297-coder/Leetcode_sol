class Solution {
public:
    int minMoves(vector<int>& nums) {

        int to_be = *min_element(nums.begin(), nums.end());

        int sum = accumulate(nums.begin(), nums.end(), 0);

        return sum - (to_be * nums.size());
    }
};