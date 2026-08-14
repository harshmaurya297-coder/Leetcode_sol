class Solution {
public:
    int maximumLengthSubstring(string s) {
        if(s.size() == 2) return 2;

        int ans = 0, l = 0, r = 0;
        map<char, int>mp;
        
        while(r != s.size()){
            mp[s[r]]++;        
            while (mp[s[r]] > 2) {
                mp[s[l]]--;
                l++;
            }
            ans = max(r - l + 1, ans);
            r++;
        }
        return ans;
    }
};