#include<iostream>
#include<cstring>
using namespace std;

const int N = 110;

int n;
int xs, ys, xe, ye;
char g[N][N];
bool st[N][N];

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

bool dfs(int x, int y) {
    if (g[x][y] == '#') return false;
    if (x == xe && y == ye) return true;
    st[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= n) continue;
        if (st[a][b] || g[a][b] == '#') continue;
        if (dfs(a, b)) return true;
    }
    return false;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        memset(st, false, sizeof st);
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> g[i];
        cin >> xs >> ys >> xe >> ye;
        if (dfs(xs, ys)) puts("YES");
        else puts("NO");
    }
    return 0;
}