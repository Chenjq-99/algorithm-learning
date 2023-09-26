#include<bits/stdc++.h>

using namespace std;

int f[100010][21], a[100010], v[100010], n, q;

vector<int> c[100010];

bool st[100010];

int main() {
    for (int i = 2; i <= 100010; i++) {
        if (!st[i]) {
            c[i].push_back(i);
            for (int j = i; j <= 100010; j += i) {
                st[j] = true;
                c[j].push_back(i);
            }
        }
    }

    scanf("%d%d", &n, &q);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    
    memset(v, 0x3f, sizeof(v));

    f[n + 1][0] = n + 1;
    for (int i = n; i; i--) {
        f[i][0] = f[n + 1][0];
        for (int j : c[a[i]]) {
             f[i][0] = min(f[i][0], v[j]);
             v[j] = i;
        }
    }

    for (int i = 1; i <= 20; i++)
        for (int j = 1; j <= n; j++)
            f[j][i] = f[f[j][i - 1]][i - 1];
    
    while (q--) {
        int l, r;
        int ans = 0;
        scanf("%d%d", &l, &r);
        for (int i = 20; i >= 0; i--) 
            if (f[l][i] <= r)
                l = f[l][i], ans += 1 << i;
        ans++;
        printf("%d\n", ans);
    }

    return 0;
}