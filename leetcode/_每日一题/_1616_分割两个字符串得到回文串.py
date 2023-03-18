# https://leetcode.cn/problems/split-two-strings-to-make-palindrome/
class Solution:
    def checkPalindromeFormation(self, a: str, b: str) -> bool:
        def f(a,b):
            i,j=0,len(b)-1
            while i <= j and a[i] == b[j]:
                i += 1
                j -= 1
            if j < i: return True
            return a[i:j+1]==a[i:j+1][::-1] or b[i:j+1]==b[i:j+1][::-1]
        return f(a,b) or f(b,a)