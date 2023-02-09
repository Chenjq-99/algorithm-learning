#include<vector>
#include<cstring>
using namespace std;
// https://leetcode.cn/problems/house-robber/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int f[n];
        memset(f, 0, sizeof f);
        f[0] = nums[0], f[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) 
            f[i] = max(f[i - 1], f[i - 2] + nums[i]);
        return f[n - 1];
    }
};

// 2023-02-09 参考0x3f视频并练习使用python，https://www.bilibili.com/video/BV1Xj411K7oF/?spm_id_from=333.337.search-card.all.click&vd_source=ea4c7f6cec7348f957fc3bf2130b63e2
/*
class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        # 回溯 O(2^n) TLE
        # def dfs(i):
        #     if i < 0:
        #         return 0
        #     res = max(dfs(i - 1), dfs(i - 2) + nums[i])
        #     return res
        # return dfs(n - 1)
        # 记忆化搜索
        # memo = [-1] * n
        # def dfs(i):
        #     if i < 0:
        #         return 0
        #     if memo[i] != -1:
        #         return memo[i]
        #     res = max(dfs(i - 1), dfs(i - 2) + nums[i])
        #     memo[i] = res
        #     return res
        # return dfs(n - 1)
        # 动态规划
        # f = [0] * (n + 2)
        # for i, x in enumerate(nums):
        #     f[i + 2] = max(f[i + 1], f[i] + x)
        # return f[n + 1]
        # 空间优化
        # 只用到了f[i - 1] f[i - 2],用两个变量代替f0, f1
        f0 = f1 = 0
        for i, x in enumerate(nums):
            newf = max(f1, f0 + x)
            f0 = f1
            f1 = newf
        return f1
*/