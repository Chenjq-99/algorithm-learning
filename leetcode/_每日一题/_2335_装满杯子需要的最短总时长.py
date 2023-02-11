# https://leetcode.cn/problems/minimum-amount-of-time-to-fill-cups
import heapq
class Solution:
    def fillCups(self, amount: list[int]) -> int:
        amount.sort()
        if amount[2] > amount[1] + amount[0]:
            return amount[2]
        return (sum(amount) + 1) // 2

# สนำรถั
class Solution:
    def fillCups(self, amount: list[int]) -> int:
        amount = [-x for x in amount]
        cnt = 0
        heapq.heapify(amount)
        a = heapq.heappop(amount)
        b = heapq.heappop(amount)
        while b:
            cnt += 1
            heapq.heappush(amount, a + 1)
            heapq.heappush(amount,b + 1)
            a = heapq.heappop(amount)
            b = heapq.heappop(amount)
        return cnt - a