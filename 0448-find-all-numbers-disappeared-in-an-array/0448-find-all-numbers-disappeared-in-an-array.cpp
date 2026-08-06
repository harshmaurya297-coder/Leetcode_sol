class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int j = 0, n = nums.size();
        vector<int>hash(n,0);
        for(int i = 0; i < n; i++){
            hash[nums[i] -1]++;
        }

        for(int i = 0; i < n; i++){
            if(hash[i] == 0) ans.push_back(i + 1);
        }

        return ans;
    }
};