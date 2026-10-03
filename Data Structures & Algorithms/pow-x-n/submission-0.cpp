class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0.;
        if (n == 0) return 1.;

        auto res = myPow(x, abs(n/2));
        res *= res;
        res = abs(n) % 2 ? res * x : res;

        return n > 0 ? res : 1 / res;
    }
};
