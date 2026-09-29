class Solution {
public:
    int missingNumber(vector<int>& nums) {
        bitset<1001> bs;

        for (auto& num : nums) {
            bs.set(num);
        }

        for (int i = 0; i < bs.size(); ++i) {
            if (!bs[i]) return i;
        }
    }
};
