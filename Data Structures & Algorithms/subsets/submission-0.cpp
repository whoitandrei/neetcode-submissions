class Solution {
    vector<vector<int>> res;
    vector<int> cur;

    void dfs(vector<int>& nums, int i) {
        if (i == nums.size()) {
            res.push_back(cur);
            return;
        }

        cur.push_back(nums[i]);
        dfs(nums, i + 1);
        cur.pop_back();

        dfs(nums, i + 1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
};
