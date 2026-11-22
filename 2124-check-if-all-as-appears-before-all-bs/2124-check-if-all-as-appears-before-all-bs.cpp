class Solution {
public:
    bool checkString(string s) {
        int n  = s.size();
        int idx = -1;
        for(int i = 0; i < n; i++){
            if(s[i] =='b') {
                idx = i;
                break;
            }
        }
        if(idx == -1) return true;
        for(int i = idx; i < n;  i++){
            if(s[i] == 'a') return false;
        }
        return true;
    }
};