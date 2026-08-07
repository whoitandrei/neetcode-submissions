class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int lHigh = 0, rHigh = 0;
        int res = 0;

        while (l < r) {
            if (height[l] < height[r]) {
                lHigh = max(lHigh, height[l]);
                res += lHigh - height[l];
                ++l;
            } else {
                rHigh = max(rHigh, height[r]);
                res += rHigh - height[r];
                --r;
            }
        }

        return res;
    }
};
