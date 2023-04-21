// https://leetcode.cn/problems/smallest-even-multiple
class Solution {
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
public:
    int smallestEvenMultiple(int n) {
        return 2 * n / gcd(2, n);
    }
};