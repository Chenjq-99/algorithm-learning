#include<string>
using namespace std;
// https://leetcode.cn/problems/count-number-of-homogenous-substrings/
class Solution {
    int MOD = 1e9 + 7;
public:
    int countHomogenous(string s) {
        int n = s.size();
        long long l = 0, r = 0;
        int res = 0;
        while (r < n) {
            while (s[l] == s[r]) {
                r++;
            }
            res += (r - l) * (1 + r - l) / 2 % MOD;
            l = r;
        }
        return res;
    }
};