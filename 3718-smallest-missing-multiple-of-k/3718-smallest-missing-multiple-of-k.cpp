class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int p;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == k*p){
                p++;
            }
        }
        return p*k;
    }
};