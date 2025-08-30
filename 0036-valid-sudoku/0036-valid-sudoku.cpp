class Solution {
public:
    bool isValidPlacement(vector<vector<char>>& board, int row, int col, char num) {
        for (int j = 0; j < 9; ++j) {
            if (j != col && board[row][j] == num) {
                return false;
            }
        }
        for (int i = 0; i < 9; ++i) {
            if (i != row && board[i][col] == num) {
                return false;
            }
        }
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if ((startRow + i != row || startCol + j != col) && board[startRow + i][startCol + j] == num) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (!isValidPlacement(board, i, j, board[i][j])) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};