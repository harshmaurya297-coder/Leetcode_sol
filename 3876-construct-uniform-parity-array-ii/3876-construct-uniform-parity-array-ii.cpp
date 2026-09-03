class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini_ele = *min_element(nums1.begin(), nums1.end());
        int even = 0;
        
        int mini_even = INT_MAX, mini_odd = INT_MAX;
        for(int i = 0; i < nums1.size(); i++){
            if(nums1[i]%2 == 0){
                even++;
                mini_even = min(nums1[i], mini_even);
            }
            else{
                mini_odd = min(nums1[i], mini_odd);
            }
        }

        if (mini_odd == INT_MAX || mini_odd < mini_even)
            return true;

        return false;
    }
};