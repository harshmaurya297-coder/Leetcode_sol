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
    int modifiedHeight(TreeNode* root){
        if(root == NULL) return 0;

        int lh = modifiedHeight(root -> left);
        int rh = modifiedHeight(root -> right);
        if(lh == -1) return -1;
        if(rh == -1) return -1;
        
         if (abs(lh - rh) > 1)  
            return -1;

        return 1 + max(lh, rh);
    }

public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        return modifiedHeight(root) != -1;

    }
};