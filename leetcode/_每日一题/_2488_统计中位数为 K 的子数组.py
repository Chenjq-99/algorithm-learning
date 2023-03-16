# https://leetcode.cn/problems/count-subarrays-with-median-k/
class Solution:
    def countSubarrays(self, nums: list, k: int) -> int:
        h = {0:1}
        idx = sum = res = 0
        while idx < len(nums):
            if nums[idx] < k: sum += -1
            elif nums[idx] > k: sum += 1
            else: break
            h[sum] = h.get(sum, 0) + 1
            idx += 1
        while idx < len(nums):
            if nums[idx] < k: sum += -1
            elif nums[idx] > k: sum += 1
            res += h.get(sum, 0) + h.get(sum - 1, 0)
            idx += 1
        return res