class Solution {
    vector<string> res;
    string cur;

    void dfs(int opened, int closed, int n) {
        if (cur.size() == 2 * n) {
            res.push_back(cur);
            return;
        }

        if (opened < n) {
            cur.push_back('(');
            dfs(opened + 1, closed, n);
            cur.pop_back();
        }

        if (closed < opened) {
            cur.push_back(')');
            dfs(opened, closed + 1, n);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        dfs(0, 0, n);
        return res;
    }
};
