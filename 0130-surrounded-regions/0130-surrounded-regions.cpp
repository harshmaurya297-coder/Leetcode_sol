class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int> (m , -1));
        queue<pair<int, int>> q;

        // first and last col
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O'){
                q.push({i, 0});
                vis[i][0] = 1;
            }
            if(board[i][m - 1] == 'O'){
                q.push({i, m - 1});
                vis[i][m - 1] = 1;
            }
        }

        // first and last row
        for(int i = 0; i < m; i++){
            if(board[0][i] == 'O'){
                q.push({0, i});
                vis[0][i] = 1;
            }
            if(board[n - 1][i] == 'O'){
                q.push({n - 1, i});
                vis[n - 1][i] = 1;
            }
        }

        int del_row[] = {-1, 0, 1, 0};
        int del_col[] = {0, -1, 0, 1};

        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = row + del_row[i];
                int ncol = col + del_col[i];

                if(nrow >= 0 && ncol >= 0 &&
                    nrow < n && ncol < m &&
                    vis[nrow][ncol] == -1 &&
                    board[nrow][ncol] == 'O'){

                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O' && vis[i][j] == -1){
                    board[i][j] = 'X';
                }
            }
        }
    }
};