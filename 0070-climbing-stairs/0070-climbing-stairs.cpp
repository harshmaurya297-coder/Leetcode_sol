class Solution {
public:
    int climbStairs(int n) {
        int prev = 1, prev1 = 0; 
        for(int i=1;i<=n;i++){
            int curr = prev + prev1;
            prev1 = prev;
            prev = curr;
        }
        return prev;
    }
};