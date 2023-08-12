#include <iostream>
#include <cstring>

using namespace std;

const int N = 25;

int n, m;
char g[N][N];
bool st[N][N];

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

int dfs(int x, int y) {
    st[x][y] = true;
    int res = 1;
    for (int i = 0; i < 4; i++) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= m) continue;
        if (st[a][b] || g[a][b] == '#') continue;
        res += dfs(a, b);
    }
    return res;
}

int main() {

    while(cin >> m >> n, n || m) {
        
        memset(st, false, sizeof st);
        for (int i = 0; i < n; i++)
            cin >> g[i];

        int xs, ys;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (g[i][j] == '@') {
                    xs = i, ys = j;
                    break;
                }

        cout << dfs(xs, ys) << endl;
    }
    return 0;
}