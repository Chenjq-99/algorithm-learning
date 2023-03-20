# https://leetcode.cn/problems/number-of-digit-one
class Solution:
    def countDigitOne(self, n: int) -> int:
        s = str(n)
        @cache
        def dfs(i: int, cnt1: int, is_limit: bool) -> int:
            if i == len(s):
                return cnt1
            res = 0
            up = int(s[i]) if is_limit else 9
            for d in range(up + 1):  # 枚举要填入的数字 d
                res += dfs(i + 1, cnt1 + (d == 1), is_limit and d == up)
            return res
        return dfs(0, 0, True)
