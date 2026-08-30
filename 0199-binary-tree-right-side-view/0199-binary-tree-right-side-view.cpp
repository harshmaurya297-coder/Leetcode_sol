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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                auto node = q.front();
                q.pop();

                if (node -> right != NULL) 
                    q.push(node->right);
                
                if (node -> left != NULL) 
                    q.push(node->left);
                
                if(i == 0)
                    ans.push_back(node -> val);
            }
        }
        return ans;
    }
};