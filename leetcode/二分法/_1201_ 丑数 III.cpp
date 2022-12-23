#include<numeric>
#include<math.h>
using namespace std;
class Solution {
public:
// 这道题  a b c 的范围是1-1e9 计算最小公倍数可能会爆int, 因此需要long数据类型 此时 lcm函数要添加泛型，否则会出现误差
// 由于 这道题给出了结果的范围是1-2e9，因此l, r 不会爆int, 但是计算mid的时候可能 l + r 会爆，写成 l + (r - l) / 2
    int nthUglyNumber(int n, int a, int b, int c) {
        long lcm_ab = lcm<long>(a, b);
        long lcm_ac = lcm<long>(a, c);
        long lcm_bc = lcm<long>(b, c);
        long lcm_abc = lcm<long>(lcm_ab, c);
        int l = min(min(a, b), c);
        int r = min(static_cast<long>(l) * n, 2000000000L);
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int cnt = mid / a + mid / b + mid / c - mid / lcm_ab - mid / lcm_ac - mid / lcm_bc + mid / lcm_abc;
            if (cnt >= n) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return r + 1;
    }
};
