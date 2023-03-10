# https://leetcode.cn/problems/subarray-sums-divisible-by-k/
class Solution:
    def subarraysDivByK(self, nums: list, k: int) -> int:
        h = {0:1}
        sum = res = 0
        for i in nums:
            sum += i
            res += h.get((sum % k), 0)
            h[sum % k] = h.get(sum % k, 0) + 1
        return res