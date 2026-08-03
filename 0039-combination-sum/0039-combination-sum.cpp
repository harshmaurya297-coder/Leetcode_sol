class Solution {
    void combi(int idx, int target, vector<int>& candidates,  vector<vector<int>>& ans, vector<int>& ds){

        if(idx == candidates.size()){
            if(target == 0)
                ans.push_back(ds);
            return;
        }
        if(target >= candidates[idx]){
            ds.push_back(candidates[idx]);
            combi(idx, target - candidates[idx], candidates, ans, ds);
            ds.pop_back();
        }
        combi(idx + 1, target, candidates, ans, ds);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        combi(0, target , candidates, ans, ds);
        return ans;
    }
};