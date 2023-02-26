# https://leetcode.cn/problems/maximum-score-words-formed-by-letters/
from collections import Counter
class Solution:
    def maxScoreWords(self, words: list[str], letters: list[str], score: list[int]) -> int:
        n = len(words)
        def dfs(i : int, left : Counter) -> int:
            if i == n: return 0
            res = dfs(i + 1, left)
            if all([ch in left.keys() and left[ch] >= words[i].count(ch) for ch in words[i]]):
                gain = sum([score[ord(ch)-ord('a')] for ch in words[i]])
                res = max(res, gain + dfs(i + 1, left - Counter(words[i])))
            return res
        return dfs(0, Counter(letters)) 

        