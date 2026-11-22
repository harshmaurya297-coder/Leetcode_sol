class Solution {
    bool dfs(TreeNode* root, TreeNode* target,
             vector<TreeNode*>& s) { 
        if(root == NULL) return false;

        s.push_back(root);

        if(root == target) return true;

        if(dfs(root->left, target, s)) return true;

        if(dfs(root->right, target, s)) return true;

        s.pop_back();

        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1, v2;

        dfs(root, p, v1);
        dfs(root, q, v2);

        TreeNode* ans = NULL;

        int i = 0, j = 0;

        while(i < v1.size() && j < v2.size()) {

            if(v1[i] != v2[j])
                break;

            ans = v1[i];

            i++;
            j++;
        }

        return ans;
    }
};