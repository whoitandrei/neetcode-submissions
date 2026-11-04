class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        size_t count = 0;

        for (const auto& num : nums) {
            if (count == 0) {
                candidate = num;
            }
            if (num == candidate) ++count;
            else --count;
        }
        return candidate;
    }
};