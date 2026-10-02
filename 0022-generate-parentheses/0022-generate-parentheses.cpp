class Solution {
    void rec(string t, vector<string>& s,int open, int close){
        if(open == 0 && close == 0){
            s.push_back(t);
            return;
        }
        
        if(open > 0)
            rec(t + "(", s, open - 1, close);
        if(open < close)
            rec(t + ")", s, open, close - 1);
        
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        rec("", ans, n, n);
        return ans;
    }
};