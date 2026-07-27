class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int  size = nums.size();
        sort(nums.begin(),nums.end());
        return (nums[size - 1] - 1)*(nums[size - 2] - 1);
    }
};