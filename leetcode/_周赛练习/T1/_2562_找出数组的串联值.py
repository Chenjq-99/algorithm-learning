# https://leetcode.cn/problems/find-the-array-concatenation-value/
class Solution:
    def findTheArrayConcVal(self, nums: list[int]) -> int:
        i, j = 0, len(nums) - 1
        res = 0
        while i < j:
            res += int(str(nums[i]) + str(nums[j]))
            i, j = i + 1, j - 1
        if i == j:
            res += nums[i]
        return res