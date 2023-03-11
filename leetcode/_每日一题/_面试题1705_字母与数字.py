# https://leetcode.cn/problems/find-longest-subarray-lcci/
class Solution:
    def findLongestSubarray(self, array: list) -> list:
        l = r = sum = 0
        h = {0 : -1}
        for i, v in enumerate(array):
            sum += 1 if v.isdigit() else -1
            t = h.get(sum, 1e5)
            if i - t > r - l: l, r = t + 1, i + 1 
            h[sum] = h.get(sum, i)
        return array[l : r]