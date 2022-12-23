// https://leetcode.cn/problems/valid-perfect-square/

class Solution {
public:
    bool isPerfectSquare(int num) {
        long l = 0, r = num;
        while (l < r) {
            long mid = l + r >> 1;
            if (mid * mid >= num) r = mid;
            else l = mid + 1;
        }
        return l * l == num;
    }
};