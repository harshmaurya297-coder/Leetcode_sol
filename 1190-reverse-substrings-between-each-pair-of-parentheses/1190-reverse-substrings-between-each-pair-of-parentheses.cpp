class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string str;
        
        for(char c : s){
            if (c == '(') {
                st.push(str);
                str = "";
            }
            else if (c == ')') {
                reverse(str.begin(), str.end());
                str = st.top() + str;
                st.pop();
            }
            else {
                str += c;
            }
        }
        
        return str;
    }
};