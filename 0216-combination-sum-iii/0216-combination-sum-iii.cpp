class Solution {
    void f(vector<vector<int>>& ans, vector<int>& temp, int k, int idx, int sum,
           int n) {
        if (k == 0 && sum == n) {
            ans.push_back(temp);
            sum = 0;
            return;
        }

        if (sum + idx > n || idx > 9)
            return;


        // taken
        temp.push_back(idx);
        f(ans, temp, k - 1, idx + 1, sum + idx, n);
        idx++;

        // not taken
        temp.pop_back();
        f(ans, temp, k, idx, sum, n);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(ans, temp, k, 1, 0, n);
        return ans;
    }
};