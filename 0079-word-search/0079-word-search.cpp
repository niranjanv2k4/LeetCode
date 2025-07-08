class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int n = board.size(), m = board[0].size();

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (recurse(board, i, j, word, 0, word.size()))
                    return true;
            }
        }

        return false;
    }

    bool recurse(vector<vector<char>>& board, int r, int c, string& target,
                 int len, int size) {

        if (size == len)
            return true;

        if (r < 0 || c < 0 || r == board.size() || c == board[0].size())
            return false;

        if (board[r][c] != target[len] || board[r][c] == '\0')
            return false;

        char temp = board[r][c];
        board[r][c] = '\0';

        bool left = recurse(board, r, c - 1, target, len + 1, size);
        if (left)
            return left;

        bool right = recurse(board, r, c + 1, target, len + 1, size);
        if (right)
            return right;

        bool up = recurse(board, r - 1, c, target, len + 1, size);
        if (up)
            return up;

        bool down = recurse(board, r + 1, c, target, len + 1, size);

        board[r][c] = temp;

        return down;
    }
};