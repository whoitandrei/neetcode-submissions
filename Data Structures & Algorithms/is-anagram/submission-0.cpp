class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        map<char, int> mp;

        for (int i = 0; i < s.size(); ++i) {
            mp[s[i]] += 1;
            mp[t[i]] -= 1;
        }

        for (auto& [k, v] : mp) {
            if (v != 0) return false;
        }

        return true;
    }
};
