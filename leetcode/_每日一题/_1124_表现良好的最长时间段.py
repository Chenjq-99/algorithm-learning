# https://leetcode.cn/problems/longest-well-performing-interval/description/
class Solution:
    def longestWPI(self, hours: list[int]) -> int:
        n = len(hours)
        s = [0] * (n + 1)
        for i, x in enumerate(hours):
            s[i + 1] = s[i] + (1 if x > 8 else -1)
        res = 0
        # Ŀ���ҵ�s[j] - s[i - 1] > 0 ʹ�� j - i + 1 ��� 
        stack = []
        # ��i, s[i]��ֵҪ��stack[-1]С,�����ʸ���ջ��Ҳ�����ϸ񵥵��ݼ�
        for i in range(n + 1):
            if not stack or s[stack[-1]] > s[i]:
                stack.append(i)
        # ��j�������������
        for j in range(n,-1,-1):
            while stack and s[stack[-1]] < s[j]:
                res = max(res, j - stack[-1])
                stack.pop()
        return res
