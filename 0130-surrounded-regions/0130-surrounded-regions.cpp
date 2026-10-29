class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();
        if (m == 0) return;

        queue<pair<int, int>> q;

        // Mark boundary-connected O's as safe
        auto add = [&](int r, int c) {
            if (board[r][c] == 'O') {
                board[r][c] = 'T';
                q.push({r, c});
            }
        };

        // First and last columns
        for (int i = 0; i < n; i++) {
            add(i, 0);
            add(i, m - 1);
        }

        // First and last rows
        for (int j = 0; j < m; j++) {
            add(0, j);
            add(n - 1, j);
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    board[nr][nc] == 'O') {
                    board[nr][nc] = 'T';
                    q.push({nr, nc});
                }
            }
        }

        // Restore safe cells and capture surrounded cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }
    }
};