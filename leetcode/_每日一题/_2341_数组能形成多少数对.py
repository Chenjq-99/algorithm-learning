# https://leetcode.cn/problems/maximum-number-of-pairs-in-array
from collections import Counter
class Solution:
    def numberOfPairs(self, nums: list[int]) -> list[int]:
        count = Counter(nums)
        cnt = 0
        for k, v in count.items():
            cnt += v // 2
        return [cnt, len(nums) - 2 * cnt]