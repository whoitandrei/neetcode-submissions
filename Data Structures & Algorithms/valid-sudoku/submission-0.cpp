class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        using ceilMapArray = array<unordered_set<char>, 9>;
        ceilMapArray lines, columns, ceils;

        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[row].size(); ++col) {
                if (board[row][col] == '.') continue;
                if (lines[row].contains(board[row][col])) return false;
                if (columns[col].contains(board[row][col])) return false;
                if (ceils[(row / 3) * 3 + (col / 3)].contains(board[row][col])) return false;

                lines[row].insert(board[row][col]);
                columns[col].insert(board[row][col]);
                ceils[(row / 3) * 3 + (col / 3)].insert(board[row][col]);
            }

        }

        return true;
    }
};
