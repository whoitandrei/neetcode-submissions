class Solution {
    vector<vector<int>> ans;
    vector<int> cur;

    void dfs(vector<int>& nums, int currentPosition) {
        if (currentPosition == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = currentPosition; i < nums.size(); ++i) {
            swap(nums[i], nums[currentPosition]);
            dfs(nums, currentPosition + 1);
            swap(nums[i], nums[currentPosition]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
};
