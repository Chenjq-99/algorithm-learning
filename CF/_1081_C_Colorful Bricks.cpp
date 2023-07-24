#include<bits/stdc++.h>

using namespace std;

int n, m, k, MOD = 998244353;

int f[2010][2010];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    f[1][0] = m;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= k && j < i; j++) {
            f[i][j] = f[i - 1][j] % MOD;
            if (j > 0) 
                f[i][j] = (1LL * f[i - 1][j - 1] * (m - 1) + f[i][j]) % MOD;
        }
    }
    printf("%d\n", f[n][k]);
    return 0;
}
