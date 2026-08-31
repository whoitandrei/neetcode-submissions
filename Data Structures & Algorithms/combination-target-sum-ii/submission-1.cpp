class Solution {
    vector<vector<int>> res;
    vector<int> cur;

    void dfs(vector<int>& nums, int start, int remaining) {
        if (remaining == 0) {
            res.push_back(cur);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            if (nums[i] > remaining) return;
            if (i > start && nums[i] == nums[i - 1]) continue;

            cur.push_back(nums[i]);
            dfs(nums, i + 1, remaining - nums[i]);
            cur.pop_back();
        }
        
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0, target);
        return res;
    }
};
