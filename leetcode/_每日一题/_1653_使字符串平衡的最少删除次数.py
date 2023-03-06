# https://leetcode.cn/problems/minimum-deletions-to-make-string-balanced
class Solution:
    def minimumDeletions(self, s: str) -> int:
        a, b = s.count('a'), 0
        res = a
        for i in range(len(s)):
            if s[i] == 'a': a -= 1
            else: b += 1
            if a +b < res: res = a + b
        return res
