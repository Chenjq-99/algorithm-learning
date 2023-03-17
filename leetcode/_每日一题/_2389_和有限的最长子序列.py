# https://leetcode.cn/problems/longest-subsequence-with-limited-sum/
from itertools import accumulate
from bisect import bisect_right
class Solution:
    def answerQueries(self, nums: list, queries: list) -> list:
        s = list(accumulate(sorted(nums)))
        return [bisect_right(s, x) for x in queries]