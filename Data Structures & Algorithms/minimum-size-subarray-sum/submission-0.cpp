class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<long long> prefix(nums.size() + 1, 0);

        for (int i = 0; i < nums.size(); ++i) {
            prefix[i+1] = prefix[i] + nums[i];
        }

        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); ++i) {
            auto it = lower_bound(prefix.begin() + i + 1, prefix.end(), prefix[i] + target);

            if (it != prefix.end()) {
                int j = it - prefix.begin();
                ans = min(ans, static_cast<int>(j - i));
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};