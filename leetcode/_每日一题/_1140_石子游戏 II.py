# https://leetcode.cn/problems/stone-game-ii/
class Solution:
    def stoneGameII(self, piles: list[int]) -> int:
        n = len(piles)
        @cache
        def dfs(m : int, i : int) -> int:
            if i + 2 * m >= n: return sum(piles[i:])
            res, total = 0, sum(piles[i:])
            for j in range(1, 2 * m + 1):
                res = max(res, total - dfs(max(m,j),i+j))
            return res
        return dfs(1, 0)
