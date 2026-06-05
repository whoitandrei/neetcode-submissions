class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;

        for (int i = 0; i < nums.size(); ++i) {
            int leftResult = 1;
            int rightResult = 1;

            for (int j = 0; j < i; ++j) {
                leftResult *= nums[j];
            }
            for (int j = i + 1; j < nums.size(); ++j) {
                rightResult *= nums[j];
            }

            ans.push_back(leftResult * rightResult);
        }

        return ans;
    }
};
