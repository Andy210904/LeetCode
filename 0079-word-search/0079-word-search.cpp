class Solution {
public:
    bool backtrack(vector<vector<char>>& board, string& word, int ind, int i, int j) {
        if (ind == word.size()) return true;
        int n = board.size();
        int m = board[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[ind]) return false;
        char temp = board[i][j];
        board[i][j] = '#';  
        bool found = backtrack(board, word, ind + 1, i - 1, j) ||
                     backtrack(board, word, ind + 1, i + 1, j) ||
                     backtrack(board, word, ind + 1, i, j - 1) ||
                     backtrack(board, word, ind + 1, i, j + 1);
        board[i][j] = temp;  
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0]) {
                    if (backtrack(board, word, 0, i, j)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
