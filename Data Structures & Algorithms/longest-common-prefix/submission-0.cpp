class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string longestPrefix = strs[0];

        for (int i = 1; i < strs.size(); ++i) {
            for (int j = 0; j < longestPrefix.size(); ++j) {
                if (longestPrefix[j] != strs[i][j]) {
                    longestPrefix = j > 0 ? longestPrefix.substr(0, j) : "";
                    break;
                }
            }

            if (longestPrefix == "") return "";
        }

        return longestPrefix;
    }
};