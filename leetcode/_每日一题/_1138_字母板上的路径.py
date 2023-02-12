class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        res = ""
        x = y = 0
        for ch in target:
            diff = ord(ch) - ord('a')
            newx = diff // 5
            newy = diff % 5
            if newx - x < 0:
                res += 'U' * (x - newx)
            if newy - y < 0:
                res += 'L' * (y - newy)
            if newx - x > 0:
                res += 'D' * (newx - x)
            if newy - y > 0:
                res += 'R' * (newy - y)
            res += '!'
            x, y= newx, newy
        return res
# ����д�ģ�����
class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        ans = []
        x = y = 0
        for c in target:
            nx, ny = divmod(ord(c) - ord('a'), 5)  # Ŀ��λ��
            v = "UD"[nx > x] * abs(nx - x)  # ��ֱ
            h = "LR"[ny > y] * abs(ny - y)  # ˮƽ
            ans.append((v + h if c != 'z' else h + v) + "!")
            x, y = nx, ny
        return ''.join(ans)
