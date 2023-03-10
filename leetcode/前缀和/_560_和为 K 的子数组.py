# https://leetcode.cn/problems/subarray-sum-equals-k/
class Solution:
    def subarraySum(self, nums: list, k: int) -> int:
        h = {0:1}
        sum = res = 0
        for i in nums:
            sum += i
            res += h.get(sum - k, 0)
            h[sum] = h.get(sum, 0) + 1
        return res
            

