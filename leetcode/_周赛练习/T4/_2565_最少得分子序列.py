# https://leetcode.cn/problems/subsequence-with-the-minimum-score/
# �ʼǣ�https://www.cnblogs.com/chenjq12/p/17114809.html
class Solution:
    def minimumScore(self, s: str, t: str) -> int:
        # ǰ��׺�ֽ�
        n, m = len(s), len(t)
        suf = [m] * (n + 1) # suf[i] = j ��ʾƥ���׺s[i:] ƥ���� t[j:]
        j = m - 1
        # ����ö�ٷָ�λ��,���׺ƥ��
        for i in range(n - 1, -1, -1):
            if j >= 0 and s[i] == t[j]:
                j -= 1
            suf[i] = j + 1
        # ��ʾͨ����׺ƥ�� ȥ��t[:suf[0]]
        res =  suf[0]
        # ����ö�ٷָ�λ�ã���ǰ׺ƥ�䣬���жϴ�
        j = 0
        for i in range(n):
            if j < m and s[i] == t[j]:
                j += 1
                # ���´�
                if suf[i+1] - j >= 0:
                    res = min(res, suf[i+1] - j)
        return res

