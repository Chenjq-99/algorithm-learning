# https://leetcode.cn/problems/minimum-hours-of-training-to-win-a-competition/
class Solution:
    def minNumberOfHours(self, initialEnergy: int, initialExperience: int, energy: list, experience: list) -> int:
        t = initialExperience
        h = 0
        for x in experience:
            if t <= x: 
                h += x - t + 1
                t += 2 * x - t + 1
            else:
                t += x
        return max(sum(energy) - initialEnergy + 1, 0) + h