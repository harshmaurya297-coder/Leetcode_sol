class Solution {
    int pdt(int n){
        int ans = 1;
        while(n){
            ans *= (n%10);
            n = n/10;
        }
        return ans;
    }
public:
    int smallestNumber(int n, int t) {
        int ans  = n;
        while(pdt(ans)%t != 0){
            ans++;
        }
        return ans;
    }
};