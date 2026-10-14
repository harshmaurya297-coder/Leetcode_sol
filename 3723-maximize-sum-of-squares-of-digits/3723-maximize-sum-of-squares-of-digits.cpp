class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum < 0 || sum > 9 * num) {
            return "";
        }
        string s;
        for(int i = 0; i < num; i++){
            int digit = min(9, sum);
            s += char('0' + digit);
            sum -= digit;
        }

        return s;
    }
};