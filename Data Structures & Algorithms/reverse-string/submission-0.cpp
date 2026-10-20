class Solution {
public:
    void reverseString(vector<char>& s) {
        size_t l = 0, r = s.size() - 1;
        while (l < r) {
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            ++l; --r;
        }
    }
};