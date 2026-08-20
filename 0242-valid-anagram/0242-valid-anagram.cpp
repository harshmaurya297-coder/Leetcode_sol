class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
            
        int hash[26] = {-1}, hash1[26] = {-1};

        for(auto it : s)
            hash[it - 'a']++;
        
        for(auto it : t)
            hash1[it - 'a']++;
            
        for(int i = 0; i < 26; i++) 
            if(hash[i] != hash1[i])
                return false;
        
        
        return true;
    }
};