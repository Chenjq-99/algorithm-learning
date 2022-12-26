#include<vector>
#include<numeric>
#include<cstring>
using namespace std;
// https://leetcode.cn/problems/target-sum/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // 设所有元素的和为sum，其中＋号的部分和为p，则-号的部分和为sum - p
        // p - (sum - p) = tar => p = (tar + sum) / 2;
        // 记tar + sum = x
        int x = accumulate(nums.begin(), nums.end(), target);
        // 如果 x < 0 或者 x 为奇数 则找不到p
        if (x < 0 || x & 1) return 0;
        // 问题变成：从数组中找和为x/2的子数组的数目
        x /= 2;
        int f[x + 1];
        memset(f, 0, sizeof f);
        f[0] = 1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = x; j >= nums[i]; j--) {
                f[j] += f[j - nums[i]];
            }
        }
        return f[x];
    }
};