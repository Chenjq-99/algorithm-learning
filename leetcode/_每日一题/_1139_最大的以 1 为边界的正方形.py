# https://leetcode.cn/problems/largest-1-bordered-square
class Solution:
    def largest1BorderedSquare(self, grid: list[list[int]]) -> int:
        m, n = len(grid) + 1, len(grid[0]) + 1
        f = [[[0 for _ in range(2)] for _ in range(n) ] for _ in range(m)]
        res = 0
        for i in range(1, m):
            for j in range(1, n):
                f[i][j][0] = f[i - 1][j][0] + 1 if grid[i - 1][j - 1] == 1 else 0
                f[i][j][1] = f[i][j - 1][1] + 1 if grid[i - 1][j - 1] == 1 else 0
                k = min(f[i][j][0],f[i][j][1])
                if  k > res:
                    for t in range(k, res, -1):
                        if (f[i - t + 1][j][1] >= t and f[i][j - t + 1][0] >= t):
                            res = t
                            break
        return res ** 2
        