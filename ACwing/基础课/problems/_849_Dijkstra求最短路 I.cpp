#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 510;

int g[N][N], dist[N];
bool st[N];

int m, n;

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 1; i <= n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (dist[j] < dist[t] || t == -1)) {
                t = j;
            }
        }
        st[t] = true;
        for (int j = 1; j <= n; j++) {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main () {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    while (m--) {
        int x, y, w;
        cin >> x >> y >> w;
        g[x][y] = min(g[x][y], w); // 重边只保留最短边
    }
    cout << dijkstra() <<endl;
    return 0;
}