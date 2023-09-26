/*
https://codeforces.com/contest/229/problem/B

输入 n(2≤n≤1e5) m(0≤m≤1e5) 表示一个 n 点 m 边的无向图（节点编号从 1 开始）。
然后输入 m 条边，每条边包含 3 个数 a b c(1≤c≤1e4)，表示有一条边权为 c 的无向边连接 a 和 b，表示从 a 到 b 需要 c 秒。
保证无自环、无重边。
然后输入 n 行，每行第一个数 k 表示数组 t[i] 的长度，然后输入数组 t[i]。
数组 t[i] 是一个严格递增序列，0≤t[i][j]<1e9。
所有 k 之和 ≤1e5。

初始时间为 0。你从 1 出发，要去 n。
如果你在点 i，但是当前时间在数组 t[i] 中，那么你必须等待 1 秒。如果下一秒仍然在 t[i] 中，那么继续等待 1 秒。依此类推。
输出到达 n 的最早时间。
如果无法到达 n，输出 -1。
*/

/*
https://codeforces.com/contest/229/submission/206931343

Dijkstra 的变形。
把 dis[i] 定义成可以从 i 出发的最早时间。特别地，dis[n] 定义成到 n 的最早时间。
假设在时刻 j 到达点 i，那么需要快速求出 >= j 的第一个不在 t[i] 中的数 next。可以把相邻的时间合并成区间，这样二分就能求出 next。

易错点：
1. t[1][0] = 0 的情况处理了吗？
2. t[n] 中的数据不应当考虑。
*/
#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
const int N = 100010, M = 200010;

int h[N], e[M], ne[M], w[M], idx;

int n, m, k, dist[N];
// dist[i]从1到i最短的时间，即从i离开的最短的时间

bool st[N];

struct Range {
    int l, r;
};

vector<vector<Range>> ranges(N);

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int getStartTime(int u, int t) {
    int l = 0, r = ranges[u].size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (ranges[u][mid].r >= t) r = mid;
        else l = mid + 1;
    }
    if (l < ranges[u].size() && ranges[u][l].r >= t) {
        if (ranges[u][l].l <= t) {
            t = ranges[u][l].r + 1;
        }
    }
    return t;
}
void dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    dist[1] = getStartTime(1, 0);
    pq.push({dist[1], 1});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if(st[u]) continue;
        st[u] = true;
        for (int i = h[u]; i != -1; i = ne[i]) {
            int j = e[i];
            int d = dist[u] + w[i];
            if (j != n) d = getStartTime(j, d);
            if (d < dist[j]) {
                dist[j] = d;
                pq.push({d, j});
            }
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k);
        int pre = -2, t = 0;
        while (k--) {
            scanf("%d", &t);
            if (t > pre + 1) {
                ranges[i].push_back({t, t});
            } else {
                ranges[i].back().r = t;
            }
            pre = t;
        }
    }
    dijkstra();
    if (dist[n] > 0x3f3f3f3f / 2) printf("%d\n", -1);
    else printf("%d", dist[n]);
    return 0;
}