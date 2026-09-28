class Solution {
public:
    int maxDepth(string s) {
        int open = 0, ans = 0;
        for(char ch : s){
            if(ch == '('){
                open++;
                ans = max(ans, open);
            }
            else if(ch == ')'){
                open--;
            }
        }
        return ans;
    }
};