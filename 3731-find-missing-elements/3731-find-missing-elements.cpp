class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int s = 0;
        vector<int> ans;
        for(int i = nums[0]; i <= nums.back(); i++){
             if (s < nums.size() && nums[s] == i) {
                s++;
            } else {
                ans.push_back(i);
            }
        }
        return ans;
    }
};