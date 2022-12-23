#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int m, n;
int g[N][N], dist[N];
bool st[N];
int prim() {
    memset(dist, 0x3f, sizeof dist);
    int res = 0;
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j<= n; j++) {
            if (!st[j] && (t == -1 || dist[j] < dist[t])) {
                t = j;
            }
        }
        st[t] = true;
        if (i && dist[t] == INF) return INF;
        // 先更新结果，再更新距离，避免负的自环把dist[t]更新掉
        if (i) res += dist[t];
        for (int j = 1; j <= n; j++) dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}
int main() {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    while (m--) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a][b] = g[b][a] = min(g[a][b], w);
    }
    int t = prim();
    if (t == INF) cout << "impossible" << endl;
    else cout << t << endl;
    return 0;
}