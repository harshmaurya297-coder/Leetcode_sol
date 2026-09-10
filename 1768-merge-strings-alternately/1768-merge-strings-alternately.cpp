class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged;
        
        int i = 0;
        int n = min(word1.size(), word2.size());

        while (i < n) {
            merged += word1[i];
            merged += word2[i];
            i++;
        }

        while (i < word1.size()) {
            merged += word1[i];
            i++;
        }

        while (i < word2.size()) {
            merged += word2[i];
            i++;
        }

        return merged;
    }
};