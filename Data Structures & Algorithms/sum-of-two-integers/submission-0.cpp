class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            unsigned carry = (static_cast<unsigned>(a) &
                              static_cast<unsigned>(b)) << 1;

            a = a ^ b;
            b = static_cast<int>(carry);
        }

        return a;
    }
};
