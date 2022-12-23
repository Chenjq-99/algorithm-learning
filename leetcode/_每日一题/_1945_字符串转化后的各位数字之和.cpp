#include<string>
using namespace std;
// https://leetcode.cn/problems/sum-of-digits-of-string-after-convert/
class Solution {
public:
    int getLucky(string s, int k) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            int t = s[i] - 'a' + 1;
            if (t >= 20) res += t - 18;
            else if (t >= 10) res += t - 9;
            else res += t;
        }
        while (--k) {
            int t = 0;
            while (res > 0) {
                t += res % 10;
                res /= 10;
            }
            res = t;
        }
        return res;
    }
};