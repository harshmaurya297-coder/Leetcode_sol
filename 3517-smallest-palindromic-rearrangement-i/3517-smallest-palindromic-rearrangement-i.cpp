class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.size() == 1) return s;

        int sz = s.size();
        int a[26] = {0};
        string left, mid, right;
        
        for(char it : s){
            a[it - 'a']++;
        }

        for(int i = 0; i < 26; i++){
            char ch = 'a' + i;
            int temp = a[i]/2;
            while(temp--){
                left += ch;
            }
            
            if(a[i]%2 != 0)
                mid = ch;
        }

        right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};