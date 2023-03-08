# https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/
class Solution:
    def maxValue(self, grid: list[list[int]]) -> int:
        n, m = len(grid), len(grid[0])
        f = [0] * m
        for i in range(n):
            for j in range(m):
                f[j] += grid[i][j]
                if j >= 1: f[j] = max(f[j], f[j - 1] + grid[i][j])
        return f[m - 1]
