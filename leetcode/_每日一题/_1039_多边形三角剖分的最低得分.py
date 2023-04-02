class Solution:
    def minScoreTriangulation(self, v: list) -> int:
        n = len(v)
        @cache
        def dfs(i : int, j : int) ->int:
            if i + 1 == j:
                return 0
            res = inf
            for k in range(i + 1, j):
                res = min(res, dfs(i, k) + dfs(k, j) + v[i] * v[k] * v[j])
            return res
        return dfs(0, n - 1)