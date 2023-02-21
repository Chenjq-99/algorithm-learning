# https://leetcode.cn/problems/minimum-number-of-taps-to-open-to-water-a-garden
class Solution:
    def minTaps(self, n: int, v: list[int]) -> int:
        ranges = []
        for i in range(n + 1): ranges.append([i - v[i], i + v[i]])
        ranges.sort(key = lambda x : x[0])
        st, ed, res = 0, n, 0
        for i in range(n + 1):
            j, r = i, -2e9
            while j <= n and ranges[j][0] <= st:
                r = max(r, ranges[j][1])
                j += 1
            if r < st: return -1
            res, st, i = res + 1, r, j - 1
            if r >= ed: return res
        return -1


