class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int len = 0;
        for(auto it : st){
            if(st.count(it - 1)){
                continue;
            }
            int currLen = 1;
            int next = it + 1;

            while(st.count(next)){
                currLen++;
                next++;
            }

            len = max(len, currLen);

        }
        return len;        
    }
};