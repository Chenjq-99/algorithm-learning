// https://leetcode.cn/problems/maximum-value-at-a-given-index-in-a-bounded-array/
class Solution {
    typedef long long LL;
public:
    int maxValue(int n, int index, int maxSum) {
        int l = 1, r = maxSum;
        auto check = [&] (int m) {
            LL n1 = index, n2 = n - index - 1;
            LL x = m - 1, sum = m;
            if (n1 <= x) sum += n1 * x + n1 * (n1 - 1) * (-1) / 2;
            else sum += x * x + x * (x - 1) * (-1) / 2 + (n1 - x);
            if (n2 <= x) sum += n2 * x + n2 * (n2 - 1) * (-1) / 2;
            else sum += x * x + x * (x - 1) * (-1) / 2 + (n2 - x);
            return sum <= maxSum;
        };
        while (l < r) {
            int mid = ((LL)l + r + 1) >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};