class Solution:
    def substringXorQueries(self, s: str, queries: list[list[int]]) -> list[list[int]]:
        # a ^ b = c a = b ^ c
        # 在s中找一个子串等于 first ^ second
        # 直接find
        # res = []
        # 直接find# for x in queries:
        #     substr = bin(x[0] ^ x[1])[2:]
        #     idx = s.find(substr) 
        #     if idx == -1: res.append([-1, -1])
        #     else: res.append([idx, idx + len(substr) - 1])

        # 预处理，用hash表存 {num : (l, r)}
        n, mp = len(s), {}
        for l in range(n):
            num = 0
            for r in range(l, min(l + 30, n)):
                num = (num << 1) | (ord(s[r]) & 1)
                if num not in mp or r - l < mp[num][1] - mp[num][0]:
                    mp[num] = (l, r) 
        NOT_FOUND = (-1,-1)   
        return [mp.get(x ^ y, NOT_FOUND) for x, y in queries]


            