#include <iostream>
#include <cstring>

using namespace std;

const int N = 10;

int n, m, x, y;
int ans;
bool st[N][N];

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1}, dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

void dfs(int x, int y, int cnt) {
    if (cnt == n * m) {
        ans++;
        return;
    }
    st[x][y] = true;

    for (int i = 0; i < 8; i++) {
        int a = x + dx[i], b = y + dy[b];
        if (a < 0 || a >= n || b < 0 || b >= n) continue;
        if (st[a][b]) continue;
        dfs(a, b, cnt + 1);
    }

    st[x][y] = false;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> n >> x >> y;
        dfs(x, y, 0);
        cout << ans << endl;
    }
    return 0;
}