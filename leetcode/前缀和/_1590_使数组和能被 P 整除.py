# https://leetcode.cn/problems/make-sum-divisible-by-p/
from itertools import accumulate
class Solution:
    def minSubarray(self, nums: list, p: int) -> int:
        s = list(accumulate(nums, initial=0))
        x = s[-1] % p
        res = n = len(nums)
        last = {}
        for i, v in enumerate(s):
            last[v % p] = i
            j = last.get((v - x) % p, -n)  
            res = min(res, i - j)
        return res if res < n else -1


