class Solution {
public:
    bool checkValidString(string s) {
        if(s.size() == 1 && (s[0] == ')' || s[0] == '(')) return false;
        
        int low = 0;
        int high = 0;

        for(char c : s) {

            if(c == '(') {
                low++;
                high++;
            }
            else if(c == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;     // '*' acts as ')'
                high++;    // '*' acts as '('
            }

            if(high < 0)
                return false;

            if(low < 0)
                low = 0;
        }

        return low == 0;
    }
};