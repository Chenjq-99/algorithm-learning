#include<vector>
using namespace std;
// https://leetcode.cn/problems/minimum-xor-sum-of-two-arrays/description/
class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> f(1 << n, 0x3f3f3f3f);
        f[0] = 0;
        // state => 010001000111,其中1表示nums2中选中的元素
        // f[state] 表示 nums2中选择的元素和nums1中前__builtin_popcount(state)个元素匹配的最小值
        // 遍历state各个1，和num1[__builtin_popcount(state) - 1]匹配，取最小值
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