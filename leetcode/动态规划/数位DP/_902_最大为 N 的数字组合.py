# https://leetcode.cn/problems/numbers-at-most-n-given-digit-set/
class Solution:
    def atMostNGivenDigitSet(self, digits: List[str], n: int) -> int:
        #数位DP
        s = str(n)
        #没有约束不用mask了
        @cache
        def dfs(i : int, isLimit : bool, isNum : bool) -> int:
            if i == len(s):
                return int(isNum)
            res = 0
            if not isNum: #可以跳过
                res = dfs(i + 1, False, False)
            up = s[i] if isLimit else '9'
            # 枚举数字
            for d in digits:
                if d > up: break
                res += dfs(i + 1, isLimit and d == up, True)
            return res
        return dfs(0, True, False)