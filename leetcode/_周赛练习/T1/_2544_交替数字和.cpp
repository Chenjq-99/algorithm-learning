// https://leetcode.cn/problems/alternating-digit-sum/description/
class Solution {
public:
    int alternateDigitSum(int n) {
        int res = 0, flag = true;
        while (n) {
            if (flag) res += n % 10;
            else res -= n % 10;
            n /= 10;
            flag = !flag;
        }
        return flag ? -res : res;
    }
};