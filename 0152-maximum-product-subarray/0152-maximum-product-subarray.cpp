class Solution {
    
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN, prefix = 1, suffix = 1;

        for(int i = 0; i <  nums.size(); i++){
            if(suffix == 0) suffix = 1;
            if(prefix == 0) prefix = 1;
            prefix *= nums[i];
            suffix *= nums[nums.size() - 1 - i];

            ans = max(ans, max(prefix, suffix));
        }
        return ans;
    }
};