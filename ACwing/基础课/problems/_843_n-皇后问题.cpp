#include<iostream>
using namespace std;

const int N = 20;

int n;

char g[N][N];

bool col[N], dg[N], udg[N];

void dfs(int u) { // 第u行皇后应该放在哪一列
    if (u == n) {
        for (int i = 0; i < n; i++) puts(g[i]);
        puts("");
        return;
    }
    // 枚举列
    for (int i = 0; i < n; i++) {
        if (!col[i] && !dg[i + u] && !udg[n - u + i]) {
            g[u][i] = 'Q';
            col[i] = dg[i + u] = udg[n - u + i] = true;
            dfs(u + 1);
            col[i] = dg[i + u] = udg[n - u + i] = false;
            g[u][i] = '.';
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = '.';
        }
    }
    dfs(0);
    return 0;
}
 