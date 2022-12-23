
// https://leetcode.cn/problems/guess-number-higher-or-lower/
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while (l < r) {
            int mid = l + (r - l >> 1);
            if (guess(mid) <= 0) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};