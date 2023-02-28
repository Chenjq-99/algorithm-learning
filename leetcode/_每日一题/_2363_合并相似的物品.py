# https://leetcode.cn/problems/merge-similar-items
from collections import Counter
class Solution:
    def mergeSimilarItems(self, items1: list[list[int]], items2: list[list[int]]) -> list[list[int]]:
        t = dict(Counter(dict(items1)) + Counter(dict(items2)))
        res = [[k, v] for k, v in t.items()]
        res.sort(key = lambda x : x[0])
        return res