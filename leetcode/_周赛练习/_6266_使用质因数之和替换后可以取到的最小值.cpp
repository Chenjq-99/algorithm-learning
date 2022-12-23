// https://leetcode.cn/problems/smallest-value-after-replacing-with-sum-of-prime-factors/
class Solution {
public:
    int smallestValue(int n) {
        int last = -1;
        while (n != last) {
            last = n;
            int i = 2;
            int t = 0;
            while (i <= n) {
                if (n % i == 0) {
                    t += i;
                    n /= i;
                } else {
                    i++;
                }
            }
            n = t;
        }
        return n;
    }
};