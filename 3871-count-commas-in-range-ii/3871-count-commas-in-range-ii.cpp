class Solution {
public:
    long long countCommas(long long n) {
        long long t = 1000,count = 0;
        while(n >= t){
            count += n - t + 1;
            t *= 1000;
        }
        return count;
    }
};