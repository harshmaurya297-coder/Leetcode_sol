class Solution {
    int ans = 0;

    pair<int,int> dfs(TreeNode* root){
        if(root == NULL) return {0, 0};

        auto lh = dfs(root->left); 
        auto rh = dfs(root->right);

        int sum = lh.first + rh.first + root->val;
        int n = lh.second + rh.second + 1;

        if(sum/n == root->val) ans++;
        return {sum, n};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;

    }
};