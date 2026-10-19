class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        int less = 0, equal = 0;

        for(int i = 0; i < nums.size(); i++){
            if(target > nums[i])
                less++;
            else if(nums[i] == target)
                equal++;
            
        }
        for(int i = less; i < equal + less; i++){
            ans.push_back(i);
        }
        
        return ans;
    }
};