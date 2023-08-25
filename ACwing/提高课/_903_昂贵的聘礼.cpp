#include<bits/stdc++.h>
using namespace std;

const int N = 110, INF = 0x3f3f3f3f;

int n, m;
int g[N][N], level[N];
int dist[N];
bool st[N];

int dijkstra(int down, int up) {
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    dist[0] = 0;
    for (int i = 0; i <= n; i++) {
        int t = -1;
        for (int j = 0; j <= n; j++) 
            if (!st[i] && (t == -1 || dist[i] < dist[j]))
                t = j;
        st[t] = true;
        for (int j = 0; j <= n; j++)
            if (dist[j] > dist[t] + g[t][j] && level[j] >= down && level[j] <= up)
                dist[j] = dist[t] + g[t][j];
    }
    return dist[1];
}

int main() {
    
    cin >> m >> n;
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i <= n; i++) g[i][i] = 0;
    for (int i = 1; i <= n; i++) {
        int price, cnt;
        cin >> price >> level[i] >> cnt;
        g[0][i] = price;
        while (cnt--) {
            int id, cost;
            cin >>id >> cost;
            g[id][i] = cost;
        }
    }
    int ans = INF;
    for (int i = level[1] - m; i <= level[1]; i++)
        ans = min(ans, dijkstra(i, i + m));
    cout << ans << endl;
    return 0;
};