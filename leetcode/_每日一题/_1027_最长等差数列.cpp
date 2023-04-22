#include<vector>
using namespace std;
// https://leetcode.cn/problems/longest-arithmetic-subsequence
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        // f[i][j] 以i结尾，公差为 j - 500 的最长子序列
        int n = nums.size(), ans = -2e9;
        vector<vector<int>> f(n, vector<int>(1010, 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int d = nums[i] - nums[j] + 500;
                f[i][d] = f[j][d] + 1;
                ans = max(ans, f[i][d]);
            }
        }
        return ans;
    }
};