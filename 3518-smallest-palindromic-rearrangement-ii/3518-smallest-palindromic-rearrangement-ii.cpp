// gemini

class Solution {
    long long calcPerms(const vector<int>& counts, long long k_max) {
        long long perms = 1;
        int remaining_len = 0;
        
        for (int c : counts) {
            remaining_len += c;
        }
        
        for (int i = 0; i < 26; i++) {
            if (counts[i] == 0) continue;
            
            int n = remaining_len;
            int r = counts[i];
            remaining_len -= r; 
            
            // nCr(n, r) is identical to nCr(n, n - r). Optimize by taking the minimum.
            r = min(r, n - r);
            for (int j = 1; j <= r; j++) {
                // To prevent overflow when doing (perms * n), check if it exceeds k_max
                if (perms > (k_max * j) / n) {
                    return k_max + 1; // Early exit: we have more than enough ways
                }
                perms = (perms * n) / j;
                n--;
            }
        }
        return perms;
    }
public:
    string smallestPalindrome(string s, int k) {
        if (s.size() == 1) { 
            return (k == 1) ? s : "";
        }
        
        vector<int> counts(26, 0);
        for (char ch : s) {
            counts[ch - 'a']++;
        }
        
        string mid = "";
        vector<int> half_counts(26, 0);
        int half_len = 0;
        
        // Build character pool for the left half
        for (int i = 0; i < 26; i++) {
            if (counts[i] % 2 != 0) {
                mid = string(1, 'a' + i);
            }
            half_counts[i] = counts[i] / 2;
            half_len += half_counts[i];
        }
        
        // If the total possible permutations are strictly less than k, return empty
        if (calcPerms(half_counts, k) < k) {
            return "";
        }
        
        string left = "";
        
        // Build the string character by character from left to right
        for (int step = 0; step < half_len; step++) {
            for (int i = 0; i < 26; i++) {
                if (half_counts[i] == 0) continue;
                
                // 1. Pretend we place character ('a' + i) here
                half_counts[i]--;
                
                // 2. Calculate how many permutations exist for the remaining characters
                long long ways = calcPerms(half_counts, k);
                
                // 3. Determine if the k-th permutation lies within this branch
                if (k <= ways) {
                    left += (char)('a' + i);
                    break; // Move to the next position in the string
                } else {
                    k -= ways;          // Skip this branch
                    half_counts[i]++;   // Backtrack and try the next character
                }
            }
        }
        
        string right = left;
        reverse(right.begin(), right.end());
        
        return left + mid + right;
    }
};