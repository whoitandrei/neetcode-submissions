class Solution {
    int total = 0;

    void backtrack(const vector<int>& nums, int cur, int cur_state) {
        if (cur == nums.size()) {
            total += cur_state;
            return;
        }

        backtrack(nums, cur+1, cur_state);
        backtrack(nums, cur+1, cur_state ^ nums[cur]);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        if (nums.empty()) return 0;

        backtrack(nums, 0, 0);
        return total;
    }
};