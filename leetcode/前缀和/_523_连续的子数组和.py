# https://leetcode.cn/problems/continuous-subarray-sum/
class Solution:
    def checkSubarraySum(self, nums: list, k: int) -> bool:
        h = {0:-1}
        sum = 0
        for i, v in enumerate(nums):
            sum += v
            if i - h.get(sum % k, 1e6)>= 2: return True
            h[sum % k] = h.get(sum % k, i)
        return False