#include<string>
using namespace std;
// https://leetcode.cn/problems/partition-string-into-substrings-with-values-at-most-k
class Solution {
public:
    int minimumPartition(string s, int k) {
        int res = 1;
        long long x = 0;
        for (int i = 0; i < s.size(); i++) {
            int a = s[i] - '0';
            if (a > k) return -1;
            x = x * 10 + a;
            if (x > k) res++, x = a;
        }
        return res;
    }
};