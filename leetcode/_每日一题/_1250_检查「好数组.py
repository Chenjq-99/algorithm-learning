from math import gcd
# https://leetcode.cn/problems/check-if-it-is-a-good-array/
class Solution:
    def isGoodArray(self, nums: list[int]) -> bool:
        n = len(nums)
        res = nums[0]
        for x in nums:
            res = gcd(res, x)
            if (res == 1): return True
        return False 