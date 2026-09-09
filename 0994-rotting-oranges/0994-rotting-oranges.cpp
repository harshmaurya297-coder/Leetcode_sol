class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;

        // Put ALL initially rotten oranges in queue
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                }
            }
        }

        if(q.size() == 0){
            for (auto& row : grid) {
                for (int x : row) {
                    if (x == 1)
                        return -1;
                }
            }
            return 0;
        }
        
        vector<pair<int, int>> dir = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            // Process one BFS level = one minute
            while (size--) {
                auto [r, c] = q.front();
                q.pop();
                for (auto [dr, dc] : dir) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr >= 0 && nr < rows &&
                        nc >= 0 && nc < cols &&
                        grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }
            time++;
        }

        // Check if any fresh orange remains
        for (auto& row : grid) {
            for (int x : row) {
                if (x == 1)
                    return -1;
            }
        }

        return time - 1;
    }
};