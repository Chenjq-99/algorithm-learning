// https://leetcode.cn/problems/find-the-minimum-possible-sum-of-a-beautiful-array/description/
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;


class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        LL ans = 0;
        int k = target / 2;
        if (n > k) {
            ans += 1LL * (1 + k) * k / 2;
            int m = target + n - k - 1;
            ans += 1LL * (target + m) * (n - k) / 2;
        } else {
            ans += 1LL * (1 + n) * n / 2;
        }
        return ans;        
    }
};