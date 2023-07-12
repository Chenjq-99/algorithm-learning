#include<bits/stdc++.h>

using namespace std;

int n, a[110], f[110][3], INF = 0x3f3f3f3f;

int main() {

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    memset(f, 0x3f, sizeof f);
    f[0][0] = f[0][1] = f[0][2] = 0;

    for (int i = 1; i <= n; i++) {
        f[i][0] = min(f[i - 1][0], min(f[i - 1][1], f[i - 1][2])) + 1;
        if (a[i] == 0) {
            f[i][1] = INF;
            f[i][2] = INF;
        } else if (a[i] == 1) {
            f[i][1] = min(f[i - 1][0], f[i - 1][2]);
            f[i][2] = INF;
        } else if (a[i] == 2) {
            f[i][1] = INF;
            f[i][2] = min(f[i - 1][0], f[i - 1][1]);
        } else {
            f[i][1] = min(f[i - 1][0], f[i - 1][2]);
            f[i][2] = min(f[i - 1][0], f[i - 1][1]);
        }
    }
    printf("%d\n", min(f[n][0], min(f[n][1], f[n][2])));

    return 0;
}