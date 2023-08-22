// https://atcoder.jp/contests/abc253/tasks/abc253_e

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1010, M = 5010, MOD = 998244353;
int n, m, k;
ll f[N][M], s[M];

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        f[1][i] = 1;
        s[i] = i;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j + k <= m)
                (f[i][j] += (s[m] - s[j + k - 1] + MOD) % MOD) %= MOD;
            if (j - k >= 1)
                (f[i][j] += (s[j - k]) % MOD) %= MOD;
            if (!k)
                (f[i][j] -= (s[j] - s[j - 1]) % MOD) %= MOD;
        }
        for (int j = 1; j <= m; j++)
            s[j] = (s[j - 1] + f[i][j]) % MOD;
    }
    cout << s[m] << endl;
    return 0;
}
