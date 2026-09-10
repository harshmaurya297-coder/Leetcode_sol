class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;

        vector<int>hash(256, -1);
        vector<int>hash1(256, -1);
        for(int i = 0; i < s.size(); i++){
            if(hash[s[i]] == -1 && hash1[t[i]] == -1) {
                    hash[s[i]] = t[i];
                    hash1[t[i]] = s[i];
            }
            else{

                if(hash[s[i]] != t[i] || hash1[t[i]] != s[i])
                    return false;                
            }

        }
        return true;
    }
};