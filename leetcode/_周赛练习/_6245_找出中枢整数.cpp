#include<vector>
using namespace std;
// https://leetcode.cn/problems/find-the-pivot-integer/
class Solution {
public:
    int pivotInteger(int n) {
        for (int i = 0; i <= n; i++) {
            int a = 0.5 * i * (1 + i);
            int b = 0.5 * (n - i + 1) * (i + n);
            if (a == b) return i;
        }
        return -1;
    }
};