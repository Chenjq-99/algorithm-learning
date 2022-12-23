// https://leetcode.cn/problems/arranging-coins/
class Solution {
public:
    int arrangeCoins(int n) {
        auto count = [&](long long x){return x * (x + 1) >> 1;};
        int l = 1, r = n;
        while (l < r) {
            int mid = l + (r - l + 1 >> 1);
            if (count(mid) <= n) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};