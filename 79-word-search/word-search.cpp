class Solution {
public:
    bool solve(int x, int y, vector<vector<char>>& board, string& word, int idx) {
        if (idx == word.length()) return true;

        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() ||
            board[x][y] != word[idx]) return false;

        char temp = board[x][y];
        board[x][y] = '#';  // mark visited

        bool ans = solve(x + 1, y, board, word, idx + 1) ||
                   solve(x - 1, y, board, word, idx + 1) ||
                   solve(x, y + 1, board, word, idx + 1) ||
                   solve(x, y - 1, board, word, idx + 1);

        board[x][y] = temp;  // unmark
        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (solve(i, j, board, word, 0))
                    return true;
            }
        }
        return false;
    }
};
