// https://leetcode.cn/problems/count-the-digits-that-divide-a-number/
class Solution {
public:
    int countDigits(int num) {
        int x = num, res = 0;
        for(; x; x /= 10) if (num % (x % 10) == 0) res++;
        return res;
    }
};