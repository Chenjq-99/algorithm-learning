from collections import Counter
class Solution:
    def balancedString(self, s: str) -> int:
        cnt, m = Counter(s), len(s) // 4
        if all(cnt[x] == m for x in "QWER"): return 0
        res, l = 0x3f3f3f3f, 0
        for r, c in enumerate(s):  
            cnt[c] -= 1
            while all(cnt[x] <= m for x in "QWER"):
                res = min(res, r - l + 1)
                cnt[s[l]] += 1
                l += 1  
        return res
            

