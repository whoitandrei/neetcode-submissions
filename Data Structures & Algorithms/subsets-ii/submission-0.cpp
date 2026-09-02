class Solution {
    vector<vector<int>> res;
    vector<int> cur;

    void dfs(vector<int>& nums, int start) {
        res.push_back(cur);

        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i-1]) continue;
            cur.push_back(nums[i]);
            dfs(nums, i + 1);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }
};
