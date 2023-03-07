// https://leetcode.cn/problems/number-of-ways-to-earn-points/
class Solution {
public:
    int passThePillow(int n, int time) {
        int a = time / (n - 1), b = time % (n - 1);
        if (a & 1) return n - b;
        else return 1 + b;
    }
};