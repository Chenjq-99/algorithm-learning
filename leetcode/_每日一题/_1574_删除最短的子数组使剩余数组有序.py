# https://leetcode.cn/problems/shortest-subarray-to-be-removed-to-make-array-sorted/
class Solution:
    def findLengthOfShortestSubarray(self, arr: list) -> int:
        n = len(arr)
        l, r = 0, n - 1
        while r and arr[r - 1] <= arr[r]: r -= 1
        if r == 0: return 0
        ans = r  
        while l == 0 or arr[l - 1] <= arr[l]:
            while r < n and arr[r] < arr[l]: r += 1
            ans = min(ans, r - l - 1)
            l += 1
        return ans
