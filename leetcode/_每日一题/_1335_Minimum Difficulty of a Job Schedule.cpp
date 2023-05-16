#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size(), INF = 1e9, ans = INF;
        if (n < d) return -1;
        vector<vector<int>> f(d + 1, vector<int>(n + 1, INF));
        f[0][0] = 0;
        for (int i = 1; i <= d; i++) {
            for (int j = i; j <= n; j++) {
                int mx = 0;
                for (int k = j - 1; k >= i - 1; k--) {
                    mx = max(mx, jobDifficulty[k]);
                    f[i][j] = min(f[i][j], f[i - 1][k] + mx);
                }
            }
        }
        return f[d][n];
    }
};