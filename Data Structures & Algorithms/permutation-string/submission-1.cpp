class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> countIdeal(26, 0);
        for (int i = 0; i < s1.size(); ++i) {
            countIdeal[s1[i] - 'a']++;
        }

        vector<int> countS2(26, 0);
        for (int i = 0; i < s1.size(); ++i) {
            countS2[s2[i] - 'a']++;
        }

        for (int i = s1.size(); i < s2.size(); ++i) {
            if (countS2 == countIdeal) return true;
            countS2[s2[i - s1.size()] - 'a']--;
            countS2[s2[i] - 'a']++;
        }

        return (countS2 == countIdeal);
    }
};
