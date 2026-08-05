class Solution {
    void dfs(int node, vector<int>& vis, vector<vector<int>>& isConnected){
        vis[node] = 1;
        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[node][j] == 1 && !vis[j]) {
                dfs(j, vis, isConnected);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int prov = 0;
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                prov++;
                dfs(i, vis, isConnected);
            }
        }
        return prov;
    }
};