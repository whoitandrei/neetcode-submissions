class Solution {
private:
    int f(vector<int>& piles, int k) {
        int res = 0;
        for (auto& pile : piles) {
            res += (pile + k - 1) / k;
        }
        return res;
    }
public:
    int minEatingSpeed(vector<int>& piles, int lim) {
        int l = 1;
        int h = 1;
        for (auto& pile : piles) {
            h = max(h, pile);
        }

        while (l < h) {
            int m = l + (h - l) / 2;
            if (f(piles, m) <= lim) {
                h = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};
