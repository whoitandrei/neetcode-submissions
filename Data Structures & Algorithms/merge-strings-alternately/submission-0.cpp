class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        size_t l = 0, r = 0;
        string res;

        while (l < word1.size() && r < word2.size()) {
            res.push_back(word1[l++]);
            res.push_back(word2[r++]);
        }

        if (l < word1.size()) {
            res += word1.substr(l);
        }
        if (r < word2.size()) {
            res += word2.substr(r);
        }

        return res;
    }
};