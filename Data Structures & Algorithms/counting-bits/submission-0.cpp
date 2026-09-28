class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;

        for (int i = 0; i <= n; ++i) {
            int num = i;
            int cur = 0;
            while (num > 0) {
                cur += num % 2;
                num >>= 1;
            }
            res.push_back(cur);
        }

        return res;
    }
};
