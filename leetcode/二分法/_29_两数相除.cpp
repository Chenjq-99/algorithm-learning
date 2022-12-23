#include<math.h>
#include<iostream>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT32_MIN && divisor == -1) return INT32_MAX;
        int a = abs(dividend), b = abs(divisor);
        long l = 0, r = a;
        while (l < r) {
            long mid = l + r + 1 >> 1;
            if (mid * b <= a) l = mid; 
            else r = mid - 1;
        }
        if (dividend >= 0 && divisor >= 0) return l;
        if (dividend < 0 && divisor < 0) return l;
        return (-1) * l;
    }
};