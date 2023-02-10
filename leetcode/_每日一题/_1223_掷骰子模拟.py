class Solution(object):
    def dieSimulator(self, n, rollMax):
        """
        :type n: int
        :type rollMax: List[int]
        :rtype: int
        """
        # 记忆化搜索
        '''
        MOD = 10 ** 9 + 7
        memo = [[[-1] * mx for mx in rollMax] for _ in range(n)]
        def dfs(i, last, left):
            if i == n - 1:
                return 1
            if memo[i][last][left] != -1:
                return memo[i][last][left]
            res = 0
            for j, mx in enumerate(rollMax):
                if j != last :
                    res += dfs(i + 1, j, mx - 1)
                elif left:
                    res += dfs(i + 1, last, left - 1)
            memo[i][last][left] = res % MOD
            return res % MOD
        return sum(dfs(0, j, mx - 1) for j, mx in enumerate(rollMax)) % MOD
        '''
        # 动态规划
        MOD = 10 ** 9 + 7
        m = len(rollMax)  # 6
        f = [[[0] * mx for mx in rollMax] for _ in range(n)]
        f[0] = [[1] * mx for mx in rollMax]
        for i in range(1,n):
            for j, mx in enumerate(rollMax):
                for left in range(mx):
                    res = 0
                    for last in range(m):
                        if j != last:
                            res += f[i - 1][last][-1]
                        elif left:
                            res += f[i - 1][last][left - 1]
                    f[i][j][left] = res % MOD
        return sum(f[-1][j][-1] for j in range(m)) % MOD