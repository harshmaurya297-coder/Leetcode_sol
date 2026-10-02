class Solution {
    bool row_chk(int i, int j, vector<vector<char>>& board){
        int vis[10] ={0};
        for(int k = 0; k < 9; k++){
            if (board[k][j] == '.') continue;

            int num = board[k][j] - '1';
            if (vis[num]) return false;
            vis[num] = 1;
        }
        return true;
    }
    bool col_chk(int i, int j, vector<vector<char>>& board){
        int vis[10] ={0};
        for(int k = 0; k < 9; k++){
            if (board[i][k] == '.') continue;

            int num = board[i][k] - '1';
            if (vis[num]) return false;
            vis[num] = 1;
        }
        return true;
    }
    bool Box(int row, int col, vector<vector<char>>& board) {
    int vis[9] = {0};

    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (board[i][j] == '.') continue;

            int num = board[i][j] - '1';
            if (vis[num]) return false;
            vis[num] = 1;
        }
    }
    return true;
}
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if (board[i][j] == '.') continue;

                if (!row_chk(i, j, board) ||
                    !col_chk(i, j, board) ||
                    !Box(i, j, board)) {
                    return false;
                }
            }
        }
        return true;
    }
};