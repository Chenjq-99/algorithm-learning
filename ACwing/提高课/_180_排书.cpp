#include<bits/stdc++.h>
using namespace std;

const int N = 20;

int n;
int q[N];

int f() {
    int res = 0;
    for (int i = 0; i < n - 1; i++) {
        if (q[i] + 1 != q[i + 1]) res++;
    }
    return res;
}
bool dfs(int u, int max_depth) {
    if (u + f() > max_depth) return false;
    if (f() == 0) return true;
    for (int len = 1; len <= n; len++) {
        for (int l = 0; l < n; l++) {
            int r = len + l - 1;
            int backup[N];
            for (int k = r + 1; k < n; k++) {
                memcpy(backup, q, sizeof q);
                int i, j;
                for (i = l, j = r + 1; j <= k; i++, j++)
                    q[i] = backup[j];
                for (j = l; j <= r; j++, i++)
                    q[i] = backup[j];
                if (dfs(u + 1, max_depth)) return true;
                memcpy(q, backup, sizeof backup);
            }
        }
    }
    return false;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> q[i];
        }
        int depth = 0;
        while (depth < 5 && !dfs(0, depth)) depth++;

        if (depth >= 5) puts("5 or more");
        else cout << depth << endl;
    }

    return 0;
}