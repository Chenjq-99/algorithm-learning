# https://leetcode.cn/problems/numbers-at-most-n-given-digit-set/
class Solution:
    def atMostNGivenDigitSet(self, digits: List[str], n: int) -> int:
        #��λDP
        s = str(n)
        #û��Լ������mask��
        @cache
        def dfs(i : int, isLimit : bool, isNum : bool) -> int:
            if i == len(s):
                return int(isNum)
            res = 0
            if not isNum: #��������
                res = dfs(i + 1, False, False)
            up = s[i] if isLimit else '9'
            # ö������
            for d in digits:
                if d > up: break
                res += dfs(i + 1, isLimit and d == up, True)
            return res
        return dfs(0, True, False)