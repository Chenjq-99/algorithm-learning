#include<bits/stdc++.h>

using namespace std;

const int N= 200005, M = 200005;

struct Edge {
    int u, v, w, id;
    Edge(int u = 0, int v = 0, int w = 0, int id = 0) 
        : u(u), v(v), w(w), id(id) {}
    bool operator < (const Edge &e) const {
        return w < e.w;
    }
};

Edge edges[M];

vector<Edge> g[N];

int n, m, p[N], f[N][21], depth[N], weight[N][21];

long long ans[M], sum;

int find(int x) {
    if (x == p[x])  
        return x;
    return p[x] = find(p[x]);
}

void krustal() {
    for (int i = 1; i <= m; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        int pu = find(u), pv = find(v);
        if (pu != pv) {
            p[pu] = pv;
            g[u].emplace_back(u, v, w, i);
            g[v].emplace_back(v, u, w, i);
            sum += w;
        }
    }
}
void dfs(int u) {
    for (auto &e : g[u]) {
        int v = e.v, w = e.w;
        if (!depth[v]) {
            depth[v] = depth[u] + 1;
            f[v][0] = u;
            weight[v][0] = w;
            dfs(v);
        }
    }
} 
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
        edges[i].id = i;
    }
    sort(edges + 1, edges + m + 1);
    for (int i = 1; i <=n; i++)
        p[i] = i;
        
    krustal();

    memset(depth, 0, sizeof depth);
    depth[1] = 1;
    dfs(1);

    for (int i = 1; i <= 20; i++)
        for (int j = 1; j <= n; j++) {
            f[j][i] = f[f[j][i - 1]][i - 1];
            weight[j][i] = max(weight[j][i - 1], weight[f[j][i - 1]][i - 1]);
        }

    for (int i = 1; i <= m; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w, id = edges[i].id;
        if (depth[u] < depth[v])
            swap(u, v);
            
        int maxw = 0;
        int d = depth[u] - depth[v];

        for (int j = 0; d; d /= 2, j++)
            if (d & 1) {
                maxw = max(maxw, weight[u][j]);
                u = f[u][j];
            }

        if (u != v) {
            for (int k = 20; k >= 0; k--)
                if (f[u][k] != f[v][k]) {
                    maxw = max(maxw, weight[u][k]);
                    maxw = max(maxw, weight[v][k]);
                    u = f[u][k];
                    v = f[v][k];
                }
            maxw = max(maxw, weight[u][0]);
            maxw = max(maxw, weight[v][0]);
        }
        // cout << "maxw: " << maxw << endl;
        ans[id] = sum - maxw + w;
    }
    for (int i = 1; i <= m; i++)
        printf("%lld\n", ans[i]);
    return 0;
}

