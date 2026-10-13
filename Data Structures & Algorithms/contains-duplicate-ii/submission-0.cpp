class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); ++i) {
            if (mp.contains(nums[i]) && abs(i - mp[nums[i]]) <= k) {
                return true;
            }
            if (i - k > 0) mp.erase(nums[i - k]);
            mp[nums[i]] = i;
        }

        return false;
    }
};