// https://leetcode.cn/problems/check-if-number-is-a-sum-of-powers-of-three/
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n >= 3) {
            if (n % 3 == 0) n = n / 3;
            else if ((n - 1) % 3 == 0) n = (n - 1) / 3;
            else return false;
        }
        return n != 2;
    }
};