class Solution {
    bool f(TreeNode* root, int target){
        if (root == NULL)
            return false;

        target -= root->val;
        if(root->left == NULL && root->right == NULL)
            if(target == 0)
                return true;

        return f(root->left, target) ||
        f(root->right, target);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return f(root, targetSum);
    }
};