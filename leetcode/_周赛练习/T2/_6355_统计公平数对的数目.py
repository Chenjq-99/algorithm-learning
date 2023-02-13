import bisect
class Solution:
    def countFairPairs(self, nums: list[int], lower: int, upper: int) -> int:
        ans = 0
        nums.sort()
        for j, x in enumerate(nums):
            r = bisect.bisect_right(nums, upper - x, 0, j)
            l = bisect.bisect_left(nums, lower - x, 0, j)
            ans += r - l
        return ans
