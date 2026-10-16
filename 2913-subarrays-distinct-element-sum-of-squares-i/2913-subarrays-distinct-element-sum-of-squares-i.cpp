class Solution {
    int createSubarrays(vector<int>& nums, int start, int end) {
        int sum = 0;
        // Base case
        if (start == nums.size())
            return 0;

        unordered_set<int> st;
        // Sum of distinct elements of current subarray
        for (int i = start; i <= end; i++) {
            st.insert(nums[i]);
        }

        int cnt = st.size();
        sum += cnt*cnt;

        // Extend the current subarray
        if (end < nums.size() - 1) {
            sum += createSubarrays(nums, start, end + 1);
        }
        else {
            // Move to the next starting index
            sum += createSubarrays(nums, start + 1, start + 1);
        }
        return sum;
    }

public:
    int sumCounts(vector<int>& nums) {
        if (nums.empty())
            return 0;

        return createSubarrays(nums, 0, 0);
    }
};