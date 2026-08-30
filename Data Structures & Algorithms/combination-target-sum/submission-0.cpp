class Solution {
    vector<vector<int>> res;
    vector<int> cur;

    void dfs(vector<int>& nums, int i, int remaining) {
        if (remaining == 0) {
            res.push_back(cur);
            return;
        }

        if (i == nums.size() || remaining < 0) {
            return;
        }

        cur.push_back(nums[i]);
        dfs(nums, i, remaining - nums[i]);
        cur.pop_back();

        dfs(nums, i + 1, remaining);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(nums, 0, target);
        return res;
    }
};
