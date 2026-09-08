class Solution {
    vector<vector<string>> res;
    vector<string> cur;

    bool is_palindrome(string s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            ++l;
            --r;
        }
        return true;
    }

    void backtrack(string s, int start) {
        if (start == s.size()) {
            res.push_back(cur);
            return;
        }

        for (int e = start; e < s.size(); ++e) {
            if (is_palindrome(s, start, e)) {
                cur.push_back(s.substr(start, e - start + 1));
                backtrack(s, e + 1);
                cur.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return res;
    }
};
