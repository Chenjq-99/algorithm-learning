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
# 灵神写的，惊艳
class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        ans = []
        x = y = 0
        for c in target:
            nx, ny = divmod(ord(c) - ord('a'), 5)  # 目标位置
            v = "UD"[nx > x] * abs(nx - x)  # 竖直
            h = "LR"[ny > y] * abs(ny - y)  # 水平
            ans.append((v + h if c != 'z' else h + v) + "!")
            x, y = nx, ny
        return ''.join(ans)
