   #pragma GCC optimize("Ofast,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,fma,sse4,popcnt,lzcnt,bmi,bmi2")

class Solution {
    bool path(TreeNode* root, TreeNode* p, vector<TreeNode*>& ans) {
        if (root == NULL)
            return false;

        ans.push_back(root);

        if (root == p)
            return true;

        if (path(root->left, p, ans))
            return true;

        if (path(root->right, p, ans))
            return true;

        ans.pop_back();
        return false;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> a, b;

        if (!path(root, p, a))
            return NULL;

        if (!path(root, q, b))
            return NULL;

        TreeNode* ans = NULL;

        int i = 0;

        while (i < a.size() && i < b.size()) {
            if (a[i] != b[i])
                break;

            ans = a[i];
            i++;
        }

        return ans;
    }
};