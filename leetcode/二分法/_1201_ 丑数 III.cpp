#include<numeric>
#include<math.h>
using namespace std;
class Solution {
public:
// �����  a b c �ķ�Χ��1-1e9 ������С���������ܻᱬint, �����Ҫlong�������� ��ʱ lcm����Ҫ��ӷ��ͣ������������
// ���� ���������˽���ķ�Χ��1-2e9�����l, r ���ᱬint, ���Ǽ���mid��ʱ����� l + r �ᱬ��д�� l + (r - l) / 2
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
