# https://leetcode.cn/problems/find-subarrays-with-equal-sum/description/
from collections import Counter
class Solution:
    def findSubarrays(self, nums: list) -> bool:
        return not all([val < 2 for val in Counter([nums[i] + nums[i + 1] for i in range(len(nums) - 1)]).values()])