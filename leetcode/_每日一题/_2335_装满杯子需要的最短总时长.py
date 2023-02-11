# https://leetcode.cn/problems/minimum-amount-of-time-to-fill-cups
class Solution:
    def fillCups(self, amount: list[int]) -> int:
        amount.sort()
        if amount[2] > amount[1] + amount[0]:
            return amount[2]
        return (sum(amount) + 1) // 2

