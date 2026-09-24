class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;

        int jumps = 1;
        int curMax = nums[0];
        int curPos = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (curPos >= nums.size() - 1) return jumps;
            curMax = max(curMax, i + nums[i]);
            if (i == curPos) {
                jumps++;
                curPos = curMax;
            }
        }

        return jumps;
    }
};
