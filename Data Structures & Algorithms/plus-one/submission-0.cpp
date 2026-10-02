class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        vector<int> ans;

        for (int i = digits.size() - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            ans.push_back(sum % 10);
            carry = sum / 10;
        }
        if (carry) {
            ans.push_back(carry);
        } 

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
