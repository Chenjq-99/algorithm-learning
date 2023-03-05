
# https://leetcode.cn/problems/circular-permutation-in-binary-representation/
class Solution:
    def circularPermutation(self, n: int, start: int) -> list[int]:
        ans = [0] * (1 << n)
        for i in range(1 << n):
            ans[i] = (i >> 1) ^ i ^ start
        return ans
