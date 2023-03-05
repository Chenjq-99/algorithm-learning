# https://leetcode.cn/problems/making-file-names-unique/
class Solution:
    def getFolderNames(self, names: List[str]) -> List[str]:
        h = {}
        res = []
        for name in names:
            if name not in h:
                res.append(name)
                h[name] = 1
            else:
                k = h[name]
                while name + "(" + str(k) + ")" in h:
                    k += 1
                t = name + "(" + str(k) + ")"
                res.append(t)
                h[t] = 1
                h[name] += 1
        return res