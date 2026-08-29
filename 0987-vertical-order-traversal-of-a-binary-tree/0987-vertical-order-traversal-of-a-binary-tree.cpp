/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        vector<vector<int>> ans;

        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root,{0,0}});
         
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            TreeNode* n1 = node.first;
            int x = node.second.first;
            int y = node.second.second;
            vector<int> v;
            mp[x][y].insert(n1 -> val);

            if(n1 -> left) q.push({n1 -> left,{x - 1, y + 1}});
            if(n1 -> right) q.push({n1 -> right, {x + 1, y + 1}});
        }

        for(auto it : mp){
            vector<int> col;
            for (auto q : it.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};