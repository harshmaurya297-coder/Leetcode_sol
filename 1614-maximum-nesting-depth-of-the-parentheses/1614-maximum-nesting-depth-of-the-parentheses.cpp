class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, freq = 0;
        stack<char> st;

        for(char ch : s){
            if(ch == '('){
                freq++;
                ans = max(ans, freq);
            }
            else if(ch == ')'){
                if(!st.empty() && st.top() == '('){
                    freq = 0;
                }
                else
                    freq--;
            }
        }
        return ans;
    }
};