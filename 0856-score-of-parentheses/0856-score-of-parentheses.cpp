class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        int count = 1, open = 0;
        for(int  i = 0; i < s.size(); i++){
            if(s[i] == '('){
                open++;
                count *= 2;
            }
            if(s[i] == ')'){
                open--;
                count /= 2;
                if(s[i - 1] == '('){
                    ans += count;
                }
            }
        }
        return ans;
    }
};