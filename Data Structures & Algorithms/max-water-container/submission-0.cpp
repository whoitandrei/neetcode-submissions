class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int max_area = 0;

        while (l < r) {
            max_area = max(max_area, (r - l) * min(heights[l], heights[r]));
            if (heights[l] > heights[r]) --r;
            else ++l;
        }

        return max_area;
    }
};
