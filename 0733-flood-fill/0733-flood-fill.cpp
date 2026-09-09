class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();

        vector<pair<int, int>> dir = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };
        int init = image[sr][sc];
        if(init == color) return image;
        image[sr][sc] = color;
        queue<pair<int,int>> q;
        q.push({sr, sc});
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
                        image[nr][nc] == init) {

                        image[nr][nc] = color;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return image;
    }
};