# https://leetcode.cn/problems/decrease-elements-to-make-array-zigzag/
class Solution:
    def movesToMakeZigzag(self, nums: list[int]) -> int:
        n = len(nums)
        if n == 1: return 0
        res1 = 0
        for i in range(1, n, 2):
            if i + 1 >= n: 
                res1 += 0 if nums[i - 1] - nums[i] > 0 else nums[i] - nums[i - 1] + 1
            else:
                t = min(nums[i - 1], nums[i + 1])
                res1 += 0 if t - nums[i] > 0 else nums[i] - t + 1
        res2 = 0
        for i in range(0, n, 2):
            if i - 1 < 0: 
                res2 += 0 if nums[i + 1] - nums[i] > 0 else nums[i] - nums[i + 1] + 1
            elif i + 1 >= n: 
                res2 += 0 if nums[i - 1] - nums[i] > 0 else nums[i] - nums[i - 1] + 1
            else:
                t = min(nums[i - 1], nums[i + 1])
                res2 += 0 if t - nums[i] > 0 else nums[i] - t + 1
        return min(res1, res2)