class Solution {
    vector<string> lettersMap = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    string curStr;
    vector<string> res;

    void backtrack(string digits, int curInd) {
        if (curStr.size() == digits.size()) {
            res.push_back(curStr);
            return;
        }

        int digit = (int)digits[curInd] - '2';
        for (int i = 0; i < lettersMap[digit].size(); ++i) {
            curStr.push_back(lettersMap[digit].at(i));
            backtrack(digits, curInd + 1);
            curStr.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        backtrack(digits, 0);
        return res;
    }
};
