#include<bits/stdc++.h>

using namespace std;


const int N = 3010;

int s[N], c[N], f[N][3], n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) 
        scanf("%d", &s[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    memset(f, 0x3f, sizeof f);
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        f[i][0] = c[i];
        for (int j = 1; j < i; j++) {
            if (s[i] > s[j]) {
                for (int k = 0; k < 3; k++) {
                    f[i][k] = min(f[i][k], f[i - 1][k]);
                    if (k > 0)
                        f[i][k] = min(f[i][k], f[j][k - 1] + c[i]);
                }
            }
        }
        ans = min(ans, f[i][2]);
    }
    printf("%d", ans == 0x3f3f3f3f ? -1 : ans);
    return 0;
}