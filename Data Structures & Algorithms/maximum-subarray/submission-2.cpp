class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = INT_MIN;
        int maxSum = INT_MIN;

        for (auto& num : nums) {
            if (curSum < 0) curSum = num;
            else curSum += num;

            maxSum = max(maxSum, curSum);
        }

        return maxSum;
    }
};
