# https://leetcode.cn/problems/numbers-with-repeated-digits/
class Solution:
    def numDupDigitsAtMostN(self, n: int) -> int:
        s = str(n)
        @cache
        def dfs(u : int, mask : int, isLimited : bool, isNum : bool) -> int:
            if u == len(s): 
                return int(isNum)
            ans = 0
            # ���ǰ��û���һλҲ��������
            if not isNum:
                ans += dfs(u + 1, mask, False, False)
            # ��λҪ�ȷ����ķ�Χ
            low = 0 if isNum else 1
            up = int(s[u]) if isLimited else 9
            for d in range(low, up + 1):
                if (mask >> d & 1) == 0:
                    ans += dfs(u + 1, mask | 1 << d, isLimited and d == up, True)
            return ans
        return n - dfs(0, 0, True, False)