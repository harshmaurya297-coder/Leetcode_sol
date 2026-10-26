class Solution {
    long long bfs(int i, int j, vector<vector<int>>& grid,
                  vector<vector<bool>>& vis) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;

        long long sum = 0;

        vector<pair<int, int>> dir = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            sum += grid[x][y];

            for (auto [dx, dy] : dir) {
                int r = x + dx;
                int c = y + dy;

                if (r >= 0 && r < m &&
                    c >= 0 && c < n &&
                    grid[r][c] > 0 &&
                    !vis[r][c]) {

                    vis[r][c] = true;
                    q.push({r, c});
                }
            }
        }

        return sum;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] > 0 && !vis[i][j]) {
                    long long sum = bfs(i, j, grid, vis);

                    if (sum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};