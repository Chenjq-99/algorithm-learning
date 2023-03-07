#
#include<bits/stdc++.h>
using namespace std;
// https://leetcode.cn/problems/number-of-ways-to-earn-points/
class Solution {
    static const int N = 55, M = 1010, MOD = 1e9 + 7;
    int f[N][M];
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        f[0][0] = 1;
        for (int i = 1; i <= n; i++) 
            for (int j = 0; j <= target; j++) 
                for (int k = 0; k <= types[i - 1][0] && k * types[i - 1][1] <= j; k++) 
                    f[i][j] = (f[i][j] + f[i - 1][j - k * types[i - 1][1]]) % MOD;
        return f[n][target];
    }
};