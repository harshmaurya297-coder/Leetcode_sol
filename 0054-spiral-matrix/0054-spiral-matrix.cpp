class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return {};
        
        int row = matrix.size(), col = matrix[0].size();
        vector<int> ans;
          
        int start_row = 0, end_row = row - 1;
        int start_col = 0, end_col = col - 1;
        
        while (start_row <= end_row && start_col <= end_col) {
            // Left to right
            for (int j = start_col; j <= end_col; j++)
                ans.push_back(matrix[start_row][j]);
            start_row++;

            // Top to bottom
            for (int i = start_row; i <= end_row; i++)
                ans.push_back(matrix[i][end_col]);
            end_col--;

            // Right to left
            if (start_row <= end_row) {
                for (int j = end_col; j >= start_col; j--)
                    ans.push_back(matrix[end_row][j]);
                end_row--;
            }

            // Bottom to top
            if (start_col <= end_col) {
                for (int i = end_row; i >= start_row; i--)
                    ans.push_back(matrix[i][start_col]);
                start_col++;
            }
        }

        return ans;
    }
};
