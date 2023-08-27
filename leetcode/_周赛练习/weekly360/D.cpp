// https://leetcode.cn/problems/maximize-value-of-function-in-a-ball-passing-game/
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        int n = receiver.size();
        int f[n][36];
        LL w[n][36];
        for (int i = 0; i < n; i++) 
        {
            f[i][0] = receiver[i];
            w[i][0] = i;
        }
        for(int j = 1; j < 36; ++j) 
        {
            for(int i = 0; i < n; ++i) {
                f[i][j] = f[f[i][j-1]][j-1];
                w[i][j] = w[i][j-1] + w[f[i][j-1]][j-1];
            }
        }
        LL ans = 0;
        for (int i = 0; i < n; i++)
        {
            int pos = i;
            LL sum = 0;
            for (int j = 0; j < 36; j++)
            {
                if ((k >> j) & 1) 
                {
                    sum += w[pos][j];
                    pos = f[pos][j];
                }
            } 
            ans = max(ans, sum + pos);
        }
        return ans;
    }
};
