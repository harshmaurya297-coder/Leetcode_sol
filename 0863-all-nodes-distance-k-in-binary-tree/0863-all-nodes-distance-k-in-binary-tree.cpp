class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                parent[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                parent[node->right] = node;
            }
        }

        int d = 0; // distance moved from that target node
        //bfs for target node
        q.push(target);
        unordered_set<TreeNode*> visited;
        visited.insert(target);
        while(!q.empty()){
            if(d == k) break;
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                if (node->left && visited.find(node->left) == visited.end()){
                    visited.insert(node->left);
                    q.push(node->left);
                }

                if (node->right && visited.find(node->right) == visited.end()){
                    visited.insert(node->right);
                    q.push(node->right);
                }

                if (parent.count(node) && visited.find(parent[node]) == visited.end()){
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
            d++;
        }

        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};