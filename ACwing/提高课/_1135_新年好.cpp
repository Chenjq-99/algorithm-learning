#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
typedef pair<int, int> pii;

const int N = 50010, M = 200010;

int n, m;
int source[6];
int h[N], e[M], ne[M], w[M], idx;
int dist[6][N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(int s, int dist[])
{
    memset(st, false, sizeof st);
    memset(dist, 0x3f, sizeof 4 * N);
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, s);
    while (pq.size())
    {
        auto t = pq.top();
        pq.pop();
        int ver = t.y;
        if (st[ver]) continue;
        st[ver] = true;
        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i])
            {
                dist[j] = dist[ver] + w[i];
                pq.emplace(dist[j], j);
            }
        }
    }

}

int dfs(int u, int cnt)
{
    if (cnt == 5) return 0;
    int res = 0x3f3f3f3f;
    for (int i = 1; i <= 5; i++)
    {
        if (st[i]) continue;
        st[i] = true;
        res = min(res, dist[u][source[i]] + dfs(i, cnt + 1));
        st[i] = false;
    }
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    source[0] = 1;
    for (int i = 1; i <= 5; i++) scanf("%d", &source[i]);
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }

    for (int i = 0; i < 6; i++)
    {
        dijkstra(source[i], dist[i]);
    }

    memset(st, false, sizeof st);
    st[0] = true;
    printf("%d\n", dfs(0, 0));
    return 0;
}