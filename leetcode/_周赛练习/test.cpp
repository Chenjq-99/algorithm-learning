#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        int n = words.size(), INF = 0x3f3f3f3f;
        int f[n][26][26];
        memset(f, 0x3f, sizeof f);
        f[0][words[0][0] - 'a'][words[0].back() - 'a'] = words[0].size();
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 26; j++) 
                for (int k = 0; k < 26; k++) {
                    int b = words[i][0] - 'a', e = words[i].back() - 'a';
                    if (j == e) {
                        f[i][b][k] = min(f[i][b][k], f[i - 1][j][k] + (int)words[i].size() - 1);
                    } else {
                        f[i][b][k] = min(f[i][b][k], f[i - 1][j][k] + (int)words[i].size());
                    }
                    if (k == b) {
                        f[i][j][e] = min(f[i][j][e], f[i - 1][j][k] + (int)words[i].size() - 1);
                    } else {
                        f[i][j][e] = min(f[i][j][e], f[i - 1][j][k] + (int)words[i].size());
                    }
                }
        }
        int ans = INF;
        for (int i = 0; i < 26; i++) 
            for (int j = 0; j < 26; j++) 
                ans = min(ans, f[n - 1][i][j]);
        return ans;
    }
};
