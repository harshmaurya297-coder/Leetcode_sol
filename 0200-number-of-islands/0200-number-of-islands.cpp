class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        int del_row[] = {-1 , 0, 1, 0};
        int del_col[] = {0, -1, 0, 1};
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    q.push({i, j});
                    grid[i][j] = '0';

                    while(!q.empty()){
                    auto [row, col] = q.front();
                    q.pop();

                    for(int k = 0; k < 4; k++){
                        int nrow = row + del_row[k];
                        int ncol = col + del_col[k];

                        if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == '1'){
                            q.push({nrow, ncol});
                            grid[nrow][ncol] = '0';
                        }
                    }
                    }
                }
            }
        }
        return ans;        
    }
};