# https://leetcode.cn/problems/make-array-zero-by-subtracting-equal-amounts/
class Solution:
    def minimumOperations(self, nums: list[int]) -> int:
        return len(set(nums) - {0})
