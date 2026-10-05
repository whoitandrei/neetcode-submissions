class Solution {
    vector<vector<string>> ans;
    vector<string> cur;

    vector<bool> columns;
    // row - col + n - 1 indexing
    vector<bool> diagonal1;
    // row + col indexing
    vector<bool> diagonal2;
public:
    void backtrack(int row, int n) {
        if (row == n) {
            ans.push_back(cur);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (columns[col]) continue;
            if (diagonal1[row - col + n - 1]) continue;
            if (diagonal2[row + col]) continue;

            cur[row][col] = 'Q';
            columns[col] = true;
            diagonal1[row - col + n - 1] = true;
            diagonal2[row + col] = true;

            backtrack(row + 1, n);

            cur[row][col] = '.';
            columns[col] = false;
            diagonal1[row - col + n - 1] = false;
            diagonal2[row + col] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        cur.assign(n, string(n, '.'));
        columns.assign(n, false);
        diagonal1.assign(2 * n - 1, false);
        diagonal2.assign(2 * n - 1, false);
        backtrack(0, n);

        return ans;
    }
};
