class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> mp;

        for (int num : nums) {
            auto it = mp.find(num);
            if (it != mp.end()) {
                return true;
            }
            mp.insert(num);
        }
        return false;
    }
};