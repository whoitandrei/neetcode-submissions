class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size(), n = nums2.size();
        int half = (m + n + 1) / 2;
        int lo = 0, hi = m;

        while (lo <= hi) {
            int i = lo + (hi - lo) / 2;
            int j = half - i;

            int aLeft  = (i == 0) ? INT_MIN : nums1[i - 1];
            int aRight = (i == m) ? INT_MAX : nums1[i];
            int bLeft  = (j == 0) ? INT_MIN : nums2[j - 1];
            int bRight = (j == n) ? INT_MAX : nums2[j];

            if (aLeft <= bRight && bLeft <= aRight) {
                if ((m + n) % 2 == 1) return std::max(aLeft, bLeft);
                return (std::max(aLeft, bLeft) + std::min(aRight, bRight)) / 2.0;
            } else if (aLeft > bRight) {
                hi = i - 1;
            } else {
                lo = i + 1;
            }
        }
        return 0.0;
    }
};
