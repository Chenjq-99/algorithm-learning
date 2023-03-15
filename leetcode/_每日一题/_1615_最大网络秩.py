# https://leetcode.cn/problems/maximal-network-rank/
class Solution:
    def maximalNetworkRank(self, n: int, roads: list) -> int:
        d = [0 for _ in range(n)]
        g = [[0 for _ in range(n)] for _ in range(n)]
        for i, j in roads:
            g[i][j] = g[j][i] = 1
            d[i], d[j] = d[i] + 1, d[j] + 1
        maxRank = 0
        for i in range(n):
            for j in range(i + 1, n):
                maxRank = max(maxRank, d[i] + d[j] - g[i][j])
        return maxRank