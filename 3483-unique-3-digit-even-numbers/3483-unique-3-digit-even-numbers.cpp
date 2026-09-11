#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,fma,sse4,popcnt,lzcnt,bmi,bmi2")
class Solution {
    void f(int idx, int n, set<int>& v,vector<int>& digits, vector<bool>& used){

        if(idx == 3){
            if (n % 2 == 0) {
                v.insert(n);
            }
            return;
        }
                
        for (int i = 0; i < digits.size(); i++) {

            if (used[i])
                continue;

            // First digit cannot be 0
            if (idx == 0 && digits[i] == 0)
                continue;

            // Last digit must be even
            if (idx == 2 && digits[i] % 2 != 0)
                continue;

            used[i] = true;
            f(idx + 1,n * 10 + digits[i], v, digits, used);

            // Backtrack
            used[i] = false;
        }
            
    }
public:
    int totalNumbers(vector<int>& digits) {
        set<int> v;
        vector<bool> used(digits.size(), false);
        f(0, 0, v, digits, used);
        return v.size();
    }
};