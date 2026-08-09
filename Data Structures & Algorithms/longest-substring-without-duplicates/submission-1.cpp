class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0, r = 0;
        int ans = 0;

        while (r < s.size()) {
            char c = s[r];

            if (mp.count(c) && mp[c] >= l) {
                l = mp[c] + 1;
            }

            mp[c] = r;
            ans = max(ans, r - l + 1);
            ++r;
        }

        return ans;
    }
};
