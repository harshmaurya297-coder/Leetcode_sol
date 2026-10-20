class Solution {
    bool isPrime(int n) {
        if (n < 2)
            return false;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }

        return true;
    }
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> rem(n, true);
        rem[0] = rem[1] = false;

        for(int i = 2; 1LL*i*i < n; i++){
            if (rem[i]) {
                for (int j = i * i; j < n; j += i) {
                    rem[j] = false;
                }
            }
        }

        int count = 0;
        for(auto it : rem){
            if(it) count++;
        }
        return count;
    }
};