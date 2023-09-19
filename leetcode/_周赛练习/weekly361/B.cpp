// https://leetcode.cn/problems/minimum-operations-to-make-a-special-number/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;


class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();
        int ans = n;
        int x = -1, y = -1;
        for (int i = 0; i < n; i++) {
            if (num[i] == '0') x = i;
            else if (num[i] == '5') y = i;
        }
        if (x != -1) ans = min(ans, n - 1);
        for (int i = x - 1; i >= 0; i--) {
            if (num[i] == '0' || num[i] == '5') {
                ans = min(ans, n - 1 - i - 1);
                break;
            }
        }
        for (int i = y - 1; i >= 0; i--) {
            if (num[i] == '2' || num[i] == '7') {
                ans = min(ans, n - 1 - i - 1);
                break;
            }
        }
        return ans;
    }
};