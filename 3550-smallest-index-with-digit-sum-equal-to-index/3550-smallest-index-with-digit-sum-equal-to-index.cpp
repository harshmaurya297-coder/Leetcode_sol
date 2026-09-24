class Solution {
    int sum(int x){
        int sum  = 0;
        while(x != 0){
            sum += x%10;
            x /= 10;
        }
        return sum;
    }
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(sum(nums[i]) == i)
                return i;
        }
        return -1;
    }
};