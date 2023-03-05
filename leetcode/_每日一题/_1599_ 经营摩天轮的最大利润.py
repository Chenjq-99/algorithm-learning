# https://leetcode.cn/problems/maximum-profit-of-operating-a-centennial-wheel/
class Solution:
    def minOperationsMaxProfit(self, customers: list[int], boardingCost: int, runningCost: int) -> int:
        if 4 * boardingCost < runningCost: return -1
        last_p, rotate_cnt, customers_remain = 0, 0, 0
        for x in customers: 
            customers_remain += x
            rotate_cnt += 1
            last_p += min(4, customers_remain) * boardingCost - runningCost
            customers_remain -= min(4, customers_remain)
        a, b = customers_remain // 4, customers_remain % 4
        rotate_cnt, last_p = rotate_cnt + a, last_p + a * (4 * boardingCost - runningCost)
        if (b * boardingCost > runningCost):
             rotate_cnt, last_p = rotate_cnt + 1, last_p + (b * boardingCost - runningCost)
        return rotate_cnt if last_p else -1
            