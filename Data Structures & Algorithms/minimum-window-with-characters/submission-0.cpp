class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.size() < t.size()) return "";

        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        int needCount = need.size();
        int have = 0;

        int l = 0;
        int bestLen = INT_MAX, bestStart = 0;

        for (int r = 0; r < s.size(); ++r) {
            char c = s[r];
            window[c]++;

            if (need.count(c) && need[c] == window[c]) {
                have++;
            }

            while (have == needCount) {
                if (r - l + 1 < bestLen) {
                    bestLen = r - l + 1;
                    bestStart = l;
                }

                char leftChar = s[l];
                window[leftChar]--;

                if (need.count(leftChar) && need[leftChar] > window[leftChar]) {
                    have--;
                }
                l++;
            }

        }

        return bestLen < INT_MAX ? s.substr(bestStart, bestLen) : "";
    }
};
