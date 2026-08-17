class Solution {
    void f(vector<vector<int>>& ans, vector<int>& temp, vector<int>& nums,
    int idx) {
        if(idx == nums.size()){
            ans.push_back(temp);
            return;
        }
        //include
        temp.push_back(nums[idx]);
        f(ans, temp, nums, idx + 1);
        //exclude
        temp.pop_back();
        f(ans, temp, nums, idx + 1);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(ans, temp, nums, 0);
        return ans;
    }
};