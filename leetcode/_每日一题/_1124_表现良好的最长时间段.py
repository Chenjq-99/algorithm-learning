# https://leetcode.cn/problems/longest-well-performing-interval/description/
class Solution:
    def longestWPI(self, hours: list[int]) -> int:
        n = len(hours)
        s = [0] * (n + 1)
        for i, x in enumerate(hours):
            s[i + 1] = s[i] + (1 if x > 8 else -1)
        res = 0
        # 目标找到s[j] - s[i - 1] > 0 使得 j - i + 1 最大 
        stack = []
        # 找i, s[i]的值要比stack[-1]小,才有资格入栈，也就是严格单调递减
        for i in range(n + 1):
            if not stack or s[stack[-1]] > s[i]:
                stack.append(i)
        # 找j，倒序遍历数组
        for j in range(n,-1,-1):
            while stack and s[stack[-1]] < s[j]:
                res = max(res, j - stack[-1])
                stack.pop()
        return res
