# https://leetcode.cn/problems/subsequence-with-the-minimum-score/
# 笔记：https://www.cnblogs.com/chenjq12/p/17114809.html
class Solution:
    def minimumScore(self, s: str, t: str) -> int:
        # 前后缀分解
        n, m = len(s), len(t)
        suf = [m] * (n + 1) # suf[i] = j 表示匹配后缀s[i:] 匹配了 t[j:]
        j = m - 1
        # 倒叙枚举分割位置,求后缀匹配
        for i in range(n - 1, -1, -1):
            if j >= 0 and s[i] == t[j]:
                j -= 1
            suf[i] = j + 1
        # 表示通过后缀匹配 去掉t[:suf[0]]
        res =  suf[0]
        # 正序枚举分割位置，求前缀匹配，并判断答案
        j = 0
        for i in range(n):
            if j < m and s[i] == t[j]:
                j += 1
                # 更新答案
                if suf[i+1] - j >= 0:
                    res = min(res, suf[i+1] - j)
        return res

