from collections import Counter
class Solution:
    def bestHand(self, ranks: list[int], suits: list[str]) -> str:
        if suits.count(suits[0]) == 5: return "Flush"
        cnt = Counter(ranks)
        if any(v >= 3 for v in cnt.values()):
            return "Three of a Kind"
        if any(v >= 2 for v in cnt.values()):
            return "Pair"
        return "High Card"