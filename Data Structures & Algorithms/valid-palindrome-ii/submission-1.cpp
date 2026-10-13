class Solution {
public:
    bool validPalindrome(string s, size_t l = 0, size_t r = 0, bool canChange = true) {

        if (r == 0) r = s.size() - 1;

        while (l < r) {
            if (s[l] != s[r]) {
                if (!canChange) return false;

                return validPalindrome(s, l + 1, r, false) ||
                    validPalindrome(s, l, r - 1, false);
            }

            ++l; --r;
        }

        return true;
    }
};