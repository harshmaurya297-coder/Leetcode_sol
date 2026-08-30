class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int max_idx = 0, min_idx = 0;
        for(auto i = 0; i < nums.size(); i++){
            if(nums[i] > nums[max_idx])
                max_idx = i;
            
            if(nums[i] < nums[min_idx])
                min_idx = i;
            
        }

        int l = min(min_idx, max_idx);
        int r = max(min_idx, max_idx);

        // 1. Remove both from the left
        int left = r + 1;

        // 2. Remove both from the right
        int right = n - l;

        // 3. Remove min from left and max from right
        int both = (l + 1) + (n - r);

        return min({left, right, both});
    }
};