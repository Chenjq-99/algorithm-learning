#include<vector>
using namespace std;
// https://leetcode.cn/problems/minimum-xor-sum-of-two-arrays/description/
class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> f(1 << n, 0x3f3f3f3f);
        f[0] = 0;
        // state => 010001000111,����1��ʾnums2��ѡ�е�Ԫ��
        // f[state] ��ʾ nums2��ѡ���Ԫ�غ�nums1��ǰ__builtin_popcount(state)��Ԫ��ƥ�����Сֵ
        // ����state����1����num1[__builtin_popcount(state) - 1]ƥ�䣬ȡ��Сֵ
        for (int state = 1; state < 1 << n; state++) {
            for (int i = 0; i < n; i++) {
                if (state & (1 << i)) {
                    f[state] = min(f[state], f[state - (1 << i)] + (nums1[__builtin_popcount(state) - 1] ^ nums2[i]));
                }
            }
        }
        return f[(1 << n) - 1];
    }
};